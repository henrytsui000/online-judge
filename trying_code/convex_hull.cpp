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

pii operator-(pii a,pii b){ return mp(a.F-b.F,a.S-b.S);}
int operator*(pii a,pii b){ return a.F*b.S-a.S*b.F;}

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
pii p[maxn];

vector<pii> up;
vector<pii> dw;

int cal(pii a,pii b,pii c){
    pii p_1=b-a,p_2=c-a;
    // cout<<p_1<<endl<<p_2<<endl;
    // cout<<p_1*p_2<<endl;
    return p_1*p_2;
}

int32_t main(){
    ifstream fin("test.txt");
    int n; fin>>n;
    rep(i,n) fin>>p[i].F>>p[i].S;
    sort(p,p+n);
    up.eb(p[0]),up.eb(p[1]);
    for(int i=2;i<n;i++){


        // cout<<"BEF:";
        // for(auto x: up) cout<<x<<',';
        cout<<endl<<"CONS:";
        cout<<up[sz(up)-2]<<up[sz(up)-1]<<p[i]<<"->";
        cout<<cal(up[sz(up)-2],up[sz(up)-1],p[i])<<endl;
        while(sz(up)>=2&&cal(up[sz(up)-2],up[sz(up)-1],p[i])>=0){
            up.pop_back();
        }
        up.eb(p[i]);

        for(auto x: up)
            cout<<x<<',';
        cout<<endl;
    }
    cout<<"ANS:";
    for(auto x: up)
        cout<<x<<',';
    cout<<endl;

    return 0;
}
/*
14
1 1
2 1
2 2
2 3
0 1

5 5
4 3
3 2
6 1
4 4

4 1
5 3
1 0
4 0

*/