#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int maxn = 1e5+5;

vector<int> edge[maxn];
vector<set<int> > ans;

void solve(){
    
}


int32_t main(){
    int n,m;
    cin>>n>>m;
    rep(i,n){
        int u,v;
        cin>>u>>v;
        edge[u].eb(v);
    }
    solve();

    for(set<int> x: ans){
        cout<<
    }
    return 0;
}