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
const int maxn = 30005;
vector<int> node[maxn];
int dep[maxn],f[maxn][16];
int n,q,t;

void dfs(int a){
    t++;
    dep[a]=t;
    for(int x:node[a]){
        f[x][0]=a;
        dfs(x);
        t--;
    }
}

int32_t main(){
    IOS;
    cin>>n>>q;
    rep1(i,n){
        int a;
        while(cin>>a&&a)
            node[i].pb(a);
    }
    dfs(1);
    rep1(j,15)
        rep1(i,n)
            f[i][j]=f[f[i][j-1]][j-1];
    
    
    while(q--){
        int a,b,cnt=0,dis=0;
        cin>>a>>b;
        if(dep[a]<dep[b])
            swap(a,b);

        for(int i=15;i>=0;i--)
            if(dep[a]-(1<<i)>=dep[b])
                a=f[a][i],dis+=(1<<i);

        if(a==b){
            cout<<a<<' '<<dis<<endl;
        }else{
            for(int i=15;i>=0;i--){
                if(f[a][i]!=f[b][i]){
                    a=f[a][i],b=f[b][i];
                    cnt+=(1<<i);
                }
            }
            cout<<f[a][0]<<' '<<dis+2*cnt+2<<endl;
        }
    }
    return 0;
}
/*
7 6
2 3 0
4 5 0
6 7 0
0
0
0
0
4 5
4 2
4 4
4 3
1 7
2 3
*/