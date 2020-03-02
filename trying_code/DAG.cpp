#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define pb push_back
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
const int maxn = 1e5;
int n,m;
vector<int> edge[maxn];
int cnt[maxn];
queue<int> qu;
vector<int> dag;
void Dag(){
    rep(i,n)
        if(!cnt[i])
            qu.push(i),dag.pb(i);
    while(!qu.empty()){
        for(auto x:edge[qu.front()]){
            cnt[x]--;
            if(!cnt[x]){
                qu.push(x),dag.pb(x);
            }
        }

        qu.pop();
    }
}
int32_t main(){
    cin>>n>>m;
    rep(i,n){
        int a,b;
        cin>>a>>b;
        edge[a].pb(b);
        cnt[b]++;
    }
    Dag();
    return 0;
}