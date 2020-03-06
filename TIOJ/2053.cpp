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
#define int ll
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
int a[2][2]={0,0,1,0};
int m[2];
int n;

void muti(){
    int tmp[2][2]={0};
    rep(i,2)
        rep(j,2)
            rep(k,2)
                tmp[j][i]+=((a[k][i]*a[j][k])%MOD);
    rep(i,2)
        rep(j,2)
            a[i][j]=tmp[i][j]%MOD;
}

void muti2(){
    int tmp[2];
    // rep(i,2)
    //     rep(j,2)
    //        tmp[i]+=(m[j]*a[i][j]%MOD);
    tmp[0]=(m[0]*a[0][0]%MOD)+(m[1]*a[0][1]%MOD);
    tmp[1]=(m[0]*a[1][0]%MOD)+(m[1]*a[1][1]%MOD);
    rep(i,2)
        m[i]=tmp[i]%MOD;
}

void gogo(int n){
    while(n){
        if(n&1){
            muti2();
        }
        muti();
        n>>=1;
    }
    cout<<m[0]<<endl;
}

int32_t main(){
    IOS;
    cin>>m[1]>>m[0]>>a[0][1]>>a[0][0]>>n;
    gogo(n-2);
    return 0;
}