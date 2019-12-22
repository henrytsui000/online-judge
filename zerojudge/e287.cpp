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

const int maxn =105;
bool graph[maxn][maxn];
int arr[maxn][maxn];
ll ans=0;

void dfs(int x,int y){
    // cout<<x<<' '<<y<<endl;
    graph[x][y]=1;
    ans+=arr[x][y];
    pii go;
    go.F=0,go.S=0;
    int now=1e6+5;
    if(arr[x-1][y]<now&&(!graph[x-1][y]))
        go.F = x-1, go.S = y, now=arr[x-1][y];
    if(arr[x+1][y]<now&&(!graph[x+1][y]))
        go.F = x+1, go.S = y, now=arr[x+1][y];
    if(arr[x][y-1]<now&&(!graph[x][y-1]))
        go.F = x, go.S = y-1, now = arr[x][y-1];
    if( arr[x][y+1] < now && (!graph[x][y+1]) )
        go.F = x, go.S = y+1, now = arr[x][y+1];
    if(go.F==0&&go.S==0)
        cout<<ans<<endl;
    else
        dfs(go.F,go.S);
}

int32_t main(){
    IOS;
    int m,n;
    cin>>n>>m;
    pii now;
    int low=1e6+5;
    rep1(i,n)
        rep1(j,m){
            cin>>arr[i][j];
            if(arr[i][j]<low)
                now.F=i,now.S=j,low=arr[i][j];
        }
    rep(i,n+2)
        graph[i][0]=graph[i][m+1]=1;
    rep(i,m+2)
        graph[0][i]=graph[n+1][i]=1;
    dfs(now.F,now.S);
    return 0;
}