#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define pb emplace_back
#define endl '\n'
const int maxn = 1e5+5;
#define int long long
vector<int> edge[maxn];

int cnt[maxn];
queue<int> qu;
int dis[maxn];
int32_t main(){
    IOS;
    int n,m;
    cin>>n>>m;
    rep(i,m){
        int a,b;
        cin>>a>>b;
        edge[a].pb(b);
        cnt[b]++;
    }

    rep1(i,n)
        if(!cnt[i])
            qu.push(i);
    int ans=0;
    while(!qu.empty()){
        for(auto x:edge[qu.front()]){
            dis[x]=max(dis[x],dis[qu.front()]+1);
            cnt[x]--;
            ans=max(ans,dis[x]);
            if(!cnt[x])
                qu.push(x);
        }
        qu.pop();
    }
    cout<<ans<<endl;
    return 0;
}