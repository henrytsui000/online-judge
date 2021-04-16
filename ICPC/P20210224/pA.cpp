#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i <(int)n; i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define eb emplace_back
const int maxn = 2e5+5;
#define sz(a) ((int)a.size())

vector<int> edge[maxn];
stack<int> st;
int vis[maxn], ph;
int nd, q;

void dfs(int n,int v){
    vis[n] = 1;
    st.push(n);
    if(n == v)
        ph = sz(st);
    for(int x : edge[n])
        if(!vis[x] && !ph)
            dfs(x, v);
    st.pop();
}

void LCA(){
    
}

void solve(){
    int u, v;
    cin >> u >> v;
    while(sz(st))
        st.pop();
    memset(vis, 0, sizeof(vis));
    dfs(u, v);
    cout<<ph*(ph+1)/2 + nd - ph<<endl;
    ph = 0;
}

int main(){
    IOS;
    cin >> nd >> q;
    rep(i, nd - 1){
        int u, v;
        cin >> u >> v;
        edge[u].eb(v);
        edge[v].eb(u);
    }
    LCA();
    while(q--){
        solve();
    }
    return 0;
}
/*
5 2
1 2
2 3
2 4
4 5
1 3
4 5


5 1
1 2
2 3
2 4
4 5
1 3
*/
