#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)n);i++)
#define IOS ios_base::sync_with_stdio(0);
#define endl '\n'
#define debug cout<<"debug"<<endl

#define MAXN 800

int m,n;
bool arr[MAXN][MAXN];
bool tri[MAXN];
void dfs(int a,int t){
    if(!tri[a]){
        tri[a]=1;
        if(a==t)
            cout<<"YES!!!"<<endl;
        rep(i,n){
            if(arr[a][i]){
                dfs(i,t);
            }
        }
    }
}

int main(){
    cin>>n>>m;
    int a,b;
    rep(i,m){
        cin>>a>>b;
        arr[a][b]=1;
    }
    rep(i,n)
        dfs(a,b);
    return 0;
}
/*input
8 32
7 4
2 5
7 5
3 7
2 1
2 2
2 4
4 4
4 7
8 5
7 5
5 2
6 7
7 5
8 8
4 7
6 3
4 1
4 4
8 7
3 4
2 6
6 1
6 8
4 5
7 5
6 6
4 4
2 6
5 3
7 4
1 3
1 3
output
yes
*/