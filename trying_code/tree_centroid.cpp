#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
using ll = long long;
using pii = pair<int,int>;
#define endl '\n'
#define F first
#define S second
#define pb emplace_back

const int maxn = 1e5+5;
vector<int> edge[maxn];
int siz[maxn];
int n,m;
void dfs(int a,int pa){
    cout<<a<<' '<<pa<<endl;
    siz[a]=1;
    for(int x:edge[a]){
        if(x!=pa){
            dfs(x,a);
            siz[a]+=siz[x];
        }
    }
}

int32_t main(){
    IOS;
    cin>>n;
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        cout<<a<<' '<<b<<endl;
        edge[b].pb(a);
        edge[a].pb(b);

    }
    rep(i,n){
        for(int x:edge[i]){
            cout<<'('<<i<<','<<x<<')'<<' ';
        }
        cout<<endl;
    }
    dfs(0,0);
    rep(i,n)
        cout<<siz[i]<<' ';
    cout<<endl;
    return 0;
}
/*
17
0 1
1 3
3 7
3 8
3 9
1 4
4 10
4 11
0 2
2 5
5 12
2 6
6 13
12 15
12 16
6 14
*/