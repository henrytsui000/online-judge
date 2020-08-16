#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<ld,ld>;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define F first
#define S second
#define rep(i,n) for(int i=0,_a,_b;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define pb push_back
#define eb emplace_back
#define mp(a,b) make_pair(a,b)
#define cans cout<<ans<<endl
#define in cout<<"in lar"<<endl
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
    out<<'('<<P.F<<','<<P.S<<')';
    return out;
}

//}}}
const ll INF64=8000000000000000000LL;
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
const ld PI=acos(-1);
const ld eps=1e-9;
//const ll p=880301;
//const ll P=31;

ll mypow(ll a,ll b){
    ll res=1LL;
    while(b){
        if(b&1) res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

const int maxn = 1e5+5;

struct st{
    int a[4];
};

st arr[maxn];

int ans=0;

struct node{
    node *lc,*rc;
    int l,r;
    int val;
    int lz_tag;
    void push(){
        lc->val+=val,rc->val+=val;
        val=0;
    }
};


node *build(int l,int r){
    if(l==r-1){
        return new node{0,0,l,r,0};
    }else{
        int mid=(l+r)>>1;
        node *ret=new node{build(l,mid),build(mid,r),l,r,0};
    }
}

void add(int l,int r,node *nd){
    if(l==nd->l&&r==nd->r){
        nd->val++;
    }else{
        int mid = (nd->l+nd->r)>>1;
        if(l>=mid){
            add(l,r,nd->rc);
        }else if(r<=mid){
            add(l,r,nd->lc);
        }else {
            add(l,mid,nd->lc);
            add(mid,r,nd->rc);
        }
    }
}

void qry(int l,int r,node* nd){
    if(nd->l==l&&nd->r==r){
        if(nd->val)
            ans +=(l-r);
    }else{
        nd->push();
        int mid=(l+r)>>1;
        if(l>=mid){
            qry(l,r,nd->rc);
        }else if(r<=mid){
            qry(l,r,nd->lc);
        }else{
            qry(l,mid,nd->lc);
            qry(mid,r,nd->rc);
        }
    }
}

bool tmp(st x,st y){
    if(x.a[3]>y.a[3])
        return true;
    else if(x.a[3]==y.a[3])
        return x.a[2]>y.a[2];
    else return false;
}

int32_t main(){
    int n;
    cin>>n;
    rep(i,n)
        rep(j,4)
            cin>>arr[i].a[j];
    
    sort(arr,arr+n,tmp);

    rep(i,n){
        rep(j,4)
            cout<<arr[i].a[j]<<' ';
        cout<<endl;    
    }

    rep(i,n){
        if()
    }



    return 0;
}
