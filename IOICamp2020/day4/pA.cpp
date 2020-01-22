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
/*
用vector紀錄該點的所有節點深度
若再加一節點，回朔去看有沒有改變深度
掃過所有節點 找出同一節點vector最/次深相加最大
*/

const int maxn = 2*1e5+5;
const int maxq = 3*1e5+5;

int siz[maxn];
int dp[maxn];
int dep[maxn];
int pdp[maxn];
int n,q;
int dst=1;
vector<int> edge[maxn];

void dfs(int a,int pa){
    dep[a]=dep[pa]+1;
    for(int x:edge[a]){
        if(x!=pa){
            dfs(x,a);
        }
    }
}

void cal(){
    dfs(1,1);
    rep(i,n){
        dst=(dep[i]>dep[dst]?i:dst);
    }
    cout<<dst<<endl;
}

int32_t main(){
    cin>>n>>q;
    rep(i,n){
        int a,b;
        cin>>a>>b;
        edge[a].eb(b);
        edge[b].eb(a);
    }
    cal();
    int ans=0;
    while(q--){
        int a,b;
        cin>>a>>b;
        a^=ans,b^=ans;
        edge[a].eb(b);
        edge[b].eb(a);

    }
    return 0;
}
/*
5 3
1 2
2 3
1 4
4 5

3 6
3 2
3 14
*/