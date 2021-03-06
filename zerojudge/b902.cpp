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
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define F first
#define S second
#define rep(i,n) for(int i=0;i<((int)n);i++)
#define REP(i,a,b) for(int i=(a);i<(int)b;i++)
#define pb push_back
#define MP(a,b) make_pair(a,b)
#define cans cout<<ans<<endl
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
#define maxn 20
#define cf cout<<">//<"<<endl
#define cl cout<<">\\\\<"<<endl
int dp[maxn][maxn];
int main(){
    IOS;
    ll m,n;
    int T;cin>>T;
    while(T--){
        cin>>m>>n;
        if(m<=1&&(m+n)%2==1)
            cf;
        else if(m<=1&&(m+n)%2==0){
            cl;
        }else if(n<=1&&(m+n)%2==0){
            cl;
        }else if(n<=1&&(m+n)%2==1)
            cf;
        else if((m+n)%2)
            cf;
        else if(m%2&&n%2)
            cl;
        else if(m==n&&m%2==0)
            cf;
        else{
            int cnt=0;
            while(m!=n){
                if(m>n)
                    m-=n;
                else n-=m;
                cnt++;
            }
            if(cnt%2)
                cl;
            else cf;
        }
    }
    return 0;
}