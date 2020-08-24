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
#define sort_uni(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define get(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
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

/******good luck******/

struct edge{
    ll from,to,nr,d;
};

const int N=10005;
int n,k,m,boss[N];
vector<edge> G[N];

int find(int x)
{
    if(boss[x]==x)
        return x;
    return boss[x]=find(boss[x]);
}

bool cmp(edge a,edge b)
{
    return a.nr>b.nr;
}

void init()
{
    cin >> n >> k >> m;

    for(int i=0;i<=n;++i){
        G[i].clear();
        boss[i]=i;
    }
    for(int i=1;i<=k;++i)
        boss[i]=1;
        
    edge arr[N];
    for(int i=0;i<m;++i){
        int a,b,d,nr;   cin >> arr[i].from >> arr[i].to >> arr[i].d >> arr[i].nr;
    }

    sort(arr,arr+m,cmp);
    for(int i=0;i<m;++i){
        int u=find(arr[i].from),v=find(arr[i].to);
        if(u!=v){
            boss[u]=v;
        }
        G[arr[i].from].push_back({0,arr[i].to,arr[i].nr,arr[i].d});
        G[arr[i].to].push_back({0,arr[i].from,arr[i].nr,arr[i].d});
        //cout << arr[i].from << " " << arr[i].to << endl;
        if(find(n)==find(1)){
            for(int j=i+1;j<m;++j){
                if(arr[i].nr==arr[j].nr){
                    G[arr[j].from].push_back({0,arr[j].to,arr[j].nr,arr[j].d});
                    G[arr[j].to].push_back({0,arr[j].from,arr[j].nr,arr[j].d});
                }
                else break;
            }
            break;
        }
    }
}

template<typename T>
using prior = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using Prior = priority_queue<T>;

void solve()
{
    ll dis[N]; memset(dis, 0x7f, sizeof(dis));
    int vis[N]; memset(vis, 0x00, sizeof(vis));
    prior<pair<int, int>> pq; /// (dis, id)
    dis[n] = 0, pq.push({0, n});
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        if (vis[p.S]) continue;
        vis[p.S] = 1;
        for (auto x : G[p.S]) {
            if (dis[x.to] > dis[p.S] + x.d) {
                dis[x.to] = dis[p.S] + x.d;
                pq.push({dis[x.to], x.to});
            }
        }
    }

    /*
    ll dis[N]; memset(dis,0x7f,sizeof(dis));
    queue<int> q;   q.push(n);  dis[n]=0;
    while(!q.empty()){
        int now=q.front();  q.pop();
        for(edge next:G[now]){
            if(next.to==now) continue;
            if(dis[next.to]>dis[now]+next.d){
                q.push(next.to);
                if(dis[next.to]>dis[now]+next.d)
                    dis[next.to]=dis[now]+next.d;
            }
        }
    }
    */

    ll MINdis=1e18;

    for(int i=1;i<=k;++i){
            MINdis=min(MINdis,dis[i]);
    }

    for(int i=1;i<=k;++i)
        if(MINdis==dis[i])
            cout << i << " ";

    cout << endl;
}

int32_t main(){
    IOS;
    int t;  cin >> t;
    for(int T=1;T<=t;++T){
        cout << "Case #" << T << ": ";
        init();
        solve();
    }
    
    return 0;
}
