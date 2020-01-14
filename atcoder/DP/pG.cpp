#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
const int maxn =1e5+5;
#define pb push_back
#define F first 
#define S second
vector<int> edge[maxn];
int n,m;
bool vis[maxn];
int dp[maxn];
void dfs(int a,int pa){
    if(edge[a].size()==0){
        dp[a]=1;
    }else{
        for(int x:edge[a]){
            dfs(x,a);
            dp[a]=max(dp[a],dp[x]+1);
        }
    }
}

int32_t main(){
    cin>>n>>m;
    rep(i,n){
        int a,b;
        cin>>a>>b;
        edge[a-1].pb(b-1);
        vis[b-1]=true;
    }
    rep(i,n){
        if(!vis[i])
            dfs(i,i);
    }
    int ans=0;
    rep(i,n){
        ans=max(dp[i],ans);
    }
    cout<<ans<<endl;
    return 0;
}