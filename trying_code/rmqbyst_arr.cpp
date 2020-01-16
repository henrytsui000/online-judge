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
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
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

const int maxn =5*1e5+5;
int st[maxn<<2];
int arr[maxn];
#define ir(x) (2*x+1)
#define il(x) (2*x)

void build(int l,int r,int nd){
    if(l==r-1){
        st[nd]=arr[l];
    }else{
        int mid=(l+r)>>1;
        build(l,mid,il(nd));
        build(mid,r,ir(nd));
        st[nd]=max(st[il(nd)],st[ir(nd)]);
    }
}

int rmq(int l,int r,int L,int R,int nd){
    if(l==L&&r==R) return st[nd];
    int mid=(l+r)>>1;
    if(R<=mid) return rmq(l,mid,L,R,il(nd));
    else if(L>=mid) return rmq(mid,r,L,R,ir(nd));
    else return max( rmq(l,mid,L,mid,il(nd)),rmq(mid,r,mid,R,ir(nd)) );
}

int32_t main(){
    IOS;
    int n;cin>>n;
    rep(i,n) cin>>arr[i];
    build(0,n,1);
    
    int q;cin>>q;
    while(q--){
        int l,r; cin>>l>>r;
        if(l>r) swap(l,r);
        cout<<rmq(0,n,l-1,r,1)<<endl;
    }
    return 0;
}
/*
10 
3 2 4 5 6 8 1 2 9 7
7 
1 5 
3 5
1 10
5 8
6 6 
2 4
2 9 
*/