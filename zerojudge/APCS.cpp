#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define eb emplace_back
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define mp(a,b) mack_pair(a,b)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'

using pii = pair<int,int>;
using ll = long long;

const int maxn = 1e5+5;

int used[maxn];
vector<int> edge[maxn];
int n;
int high[maxn];
ll ans=0;

void dfs(int a,int b){
    high[b]=high[a]+1;
    ans += high[b];
    for(int i:edge[b]){
        dfs(b,i);
    }
    cout<<ans<<endl;
    return ;
}

void solve_a(){
    rep(i,n)
        if(!used[i]){
            solve(i);
            return ;
        }
}

void solve(int a){
    cout<<a<<endl;
    high[a]=0;
    for(int i:edge[a]){
        dfs(a,i);
    }
}

int32_t main(){
    IOS;
    cin>>n;
    rep(i,n){
        int a,k;
        cin>>k;
        rep(j,k){
            cin>>a;
            edge[i].eb(a);
            used[a]=1;
        }
    }

    solve_a();
    
    return 0;
}