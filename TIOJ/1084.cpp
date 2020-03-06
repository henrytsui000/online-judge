#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define endl '\n'
#define pb emplace_back
#define F first
#define S second
using pii = pair<int,int>;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
const int maxn = 505;
const int maxm = 1300;

struct Edge{
    int num;
    int v;
};

bool vis[maxm];

vector<Edge> edge[maxm];

void dfs(int n,int pa){
    cout<<n<<endl;
    pii low={0,600};
    for(Edge a:edge[n]){
        if(!vis[a.num]){
            if(a.v<low.S){
                low.F=a.num;
                low.S=a.v;
            }
        }
    }    
    vis[low.F]=1;
    if(low.S!=600)
        dfs(low.S,n);
}

pair<int,int> arr[maxm];
int cnt[maxm];
int main(){
    IOS;
    int n;
    while(cin>>n&&n){

        rep(i,n){
            int a,b;
            cin>>a>>b;
            cnt[a]++,cnt[b]++;
            Edge tmp,tmp2;
            tmp.num=i,tmp.v=b;
            tmp2.num=i,tmp2.v=a;
            edge[a].pb(tmp);
            edge[b].pb(tmp2);
        }
        int frt=2000;
        rep(i,n)
            if(cnt[i]%2)    
                frt=min(frt,i);
        // cout<<"HERE"<<frt<<endl;
        dfs(frt,-1);
        cout<<endl;
        cout<<endl;
        memset(arr,0,sizeof(arr));
        memset(cnt,0,sizeof(cnt));
        memset(vis,0,sizeof(vis));
        rep(i,n)
            edge[i+1].clear();
    }
    return 0;
}
/*
5
3 1
2 4
5 1
3 5
1 2
0
*/