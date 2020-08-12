#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define all(a) a.begin(), a.end()
#define sz(a) ((int)a.size())
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define eb emplace_back
#define F first
#define S second
using pii = pair<int, int>;
#define mp make_pair

const int maxn = 1e5 + 5;
vector<int> edge[maxn];
int low[maxn];

void dfs(int u,int deep){

    for(auto x:edge[u])if(vis[x]){
        dfs(x,deep+1);
        if(
        vis[x]=1;
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;

    rep(i, m){
        int a,b;
        cin>>a>>b;
        edge[a].eb(b);
        edge[b].eb(a);
    }


    return 0;
}
