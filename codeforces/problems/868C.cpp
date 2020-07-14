#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<ld,ld>;
using pil = pair<int,ll>;
using pli = pair<ll,int>;
#define SQ(i) ((i)*(i))
#define mem(a, b) memset(a, (b), sizeof(a))
#define sz(i) int(i.size())
#define for(i, j, k, in) for (int i=j ; i<(k) ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=(k) ; i-=in)
#define rep(i, j) for(i, 0, j, 1)
#define rep1(i,j) for(i, 1, j+1, 1)
#define rrep(i, j) RFOR(i, j, 0, 1)
#define all(_a) _a.begin(),_a.end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define cans cout<<ans<<endl
#define F first
#define S second
#define sort_uni(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define get(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#ifdef henrytsui
#define TIME(i) Timer i(#i)
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
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
template<typename _a> ostream &operator << (ostream &_s,deque<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
class Timer {
private:
    string scope_name;
    chrono::high_resolution_clock::time_point start_time;
public:
    Timer (string name) : scope_name(name) {
        start_time = chrono::high_resolution_clock::now();
    }
    ~Timer () {
        auto stop_time = chrono::high_resolution_clock::now();
        auto length = chrono::duration_cast<chrono::microseconds>(stop_time - start_time).count();
        double mlength = double(length) * 0.001;
        debug(scope_name, mlength);
    }
};
#else
#define TIME(i)
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
#endif
 
const ll mod = 1000000007;
const ll Inf = 0x3f3f3f3f3f3f3f3f;
const int ind = 0x3f3f3f3f;
const ld pi=acos(-1);
// const ll MAXN =
 
ll mypow(ll a,ll b){
    ll res=1LL;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

/******good luck******/
const int maxn = 1e5 +5 ;
const int maxk = 17;
int cnt[maxk];
int32_t main () {
    TIME(main);
    IOS();
    int n,k;
    cin>>n>>k;
    rep(i,n){
        int tmp=0,r=0;
        rep(j,k){
            cin>>r;
            tmp+=(r<<j);
        }
        cnt[tmp]++;
    }
    bool key = false;
    if(cnt[0])
        key=true;
    else{
        rep(i,maxk)
            rep(j,maxk){
                if(cnt[i]>0&&cnt[j]>0&&(i&j)==0)
                    key=true;
            }
    }
    if(key)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
