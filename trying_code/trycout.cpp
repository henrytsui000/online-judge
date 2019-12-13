#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define eb emplace_back

const int maxn=2005;

vector<int> edge[maxn];
int vis[maxn],deg[maxn],low[maxn];
int n,m;

using ll = long long;
ll ans=0;
bool visit[maxn];
ll cnt=0;


void dfs2(int p,int n2){
    visit[p]=true;
    cnt++;
    for(auto v:edge[p]){
        if(v==n2)
            continue;
        if(!visit[v])
            dfs2(v,n2);
    }
}

void dfs(int nd,int par){
    deg[nd]=deg[par]+1;
    low[nd]=deg[nd];
    vis[nd]=true;
    for(auto v:edge[nd]){
        if(v==par){
            continue;
        }
        if(vis[v]){
            low[nd]=min(low[nd],deg[v]);
        }else{
            dfs(v,nd);
            low[nd]=min(low[nd],low[v]);
        }
    }
    if(low[nd]==deg[nd]&&nd!=1){
        memset(visit,0,sizeof(visit));
        cnt=0;
        dfs2(nd,par);
        ans=max(ans,(n-cnt)*cnt);
    }

}

int main(){
    IOS;
    cin>>n>>m;
    rep(i,m){
        int u,v;
        cin>>u>>v;
        edge[u].eb(v);
        edge[v].eb(u);
    }
    dfs(1,1);
    cout<<ans<<endl;
    return 0;
}
/*
9 11
1 2
2 3
3 4
2 4
4 5
5 6
4 6
1 7
7 9
8 9
7 8
*/
