#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
const int maxn = 1005;
const int inf = 10005;
int arr[maxn][maxn][3];
int n;
void dfs(int r,int c){
    rep(i,3)
        arr[r][c][i]=min({arr[r][c][(i+1)%3]+1,arr[r][c][(i-1)%3]+1,arr[r][c][i]});
    if(arr[r][c+1][0]>arr[r][c][0]){
        arr[r][c+1][0]=arr[r][c][0];
        dfs(r,c+1);
    }
}

int32_t main(){
    int m;
    cin>>n>>m;
    while(cin>>n>>m){
        memset(arr,inf,sizeof(arr));
        int a,b;
        rep(i,m)  
            cin>>a>>b;
            rep(i,3)          
            arr[a][b][i]=-1;
      }
      rep(i,3)
        arr[0][0][i]=1;
      dfs(0,0); 
    return 0;
}
