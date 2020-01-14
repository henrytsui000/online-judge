//r max q
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
#define mp make_pair
#define cans cout<<ans<<endl
#define in cout<<"in lar"<<endl
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
    out<<'('<<P.F<<','<<P.S<<')';
    return out;
}

#ifdef henry
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\  
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
#else
#define debug(...)
#define pary(...)
#endif

template<class T> inline bool cmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool cmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;


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
int arr[maxn];

struct Node{
    Node *lc,*rc;
    int l,r;
    int data,tag;
    void pull(){
        data=max(lc->data,rc->data);
    }
    void push(){
        if(lc&&rc){
            lc->tag+=tag;
            rc->tag+=tag;
        }
        data+=tag;
        tag=0;
    }
};

Node *root;

Node *build(int l,int r){
    if(l==r-1)
        return new Node{NULL,NULL,l,r,arr[l],0};
    int mid=(l+r)>>1;
    return new Node{build(l,mid),build(mid,r),l,r,0,0};
} 

void add(int l,int r,int val,Node* nd){
    nd->push();
    if(nd->l==l&&nd->r==r)
        nd->data+=val;
    else{
        int mid=(nd->l+nd->r)>>1;
        if(l>mid)
            add(l,r,val,nd->rc);
        else if(r<mid)
            add(l,r,val,nd->lc);
        else{
            add(l,mid,val,nd->lc);
            add(mid,r,val,nd->rc);
        }
        nd->pull();
    }
}

int qry(int l,int r,Node *nd){
    nd->push();
    if(nd->l==l&&nd->r==r)
        return nd->data;
    int mid=(nd->l+nd->r)>>1;
    if(mid>l)
        return qry(l,r,nd->rc);
    else if(mid<r)
        return qry(l,r,nd->lc);
    else
        return max(qry(l,mid,nd->lc),qry(mid,r,nd->rc));
}

/********** Good Luck :) **********/

int32_t main(){
    
    return 0;
}