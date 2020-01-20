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
#define su(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define gp(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define deg(x) (x*pi/180)
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
    out<<'('<<P.F<<','<<P.S<<')';
    return out;
}

//}}}
const ll lnf=8000000000000000000LL;
const int inf =0x3f3f3f3f; 
const ll mod=ll(1e9+7);
const ld pi=acos(-1);
const ld eps=1e-9;
//const ll p=880301;
//const ll P=31;

ll mypow(ll a,ll b){
    ll res=1LL;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

ld mt(int r,int d){return r*r*sin(deg(d))/2;}
ld mc(int r,int d){return r*r*pi*d/360;}
ld d(int a,int b,int c){return ((a*a+b*b-c*c)/(2*a*b));}
ld hur(ld d){return (sqrt(1-d*d));}
int s,m,spd,sit;

int32_t main(){
    cin>>s>>m>>spd>>sit;
    int sm=s*s*pi;
    ld l=0,r=90;
    while(l<r){
        ld mid=(l+r)/2;
        s*s-m*
        ld midcov=mc(s,mid)+mc(m,)
    }
    while(cin>>a){
        cout<<sin(deg(a))<<' '
            <<cos(deg(a))<<endl;
    }
    return 0;
}