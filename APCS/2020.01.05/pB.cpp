#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
const int maxn = 105;
int a[105][105],b[105][105];
int s,t,m,n,r;
/*
暴力搜尋
check函式是拿來計算區間[i,i+s][j,j+t]
是否是合理解答 是則回傳距離;否則-1
*/
int check(int x,int y){
    int cnt=0,dis=0;
    rep(i,s){
        rep(j,t){
            if(b[i+x][j+y]!=a[i][j])
                cnt++,dis+=(b[i+x][j+y]-a[i][j]);
            if(cnt>r)
                return -1;
        }
    }
    return abs(dis);
}

int main(){
    IOS;
    cin>>s>>t>>n>>m>>r;
    rep(i,s)
        rep(j,t)
            cin>>a[i][j];
    rep(i,n)
        rep(j,m)
            cin>>b[i][j];
    int ans=1e9+5,cnt=0;
    rep(i,n-s+1){
        rep(j,m-t+1){
            int k=check(i,j);
            if(k!=-1){
                ans=min(k,ans);
                cnt++;
            }
        }
    }
    if(cnt==0) cout<<0<<endl<<-1<<endl;
    else cout<<cnt<<endl<<ans<<endl;
    return 0;
}
/*
1 3 1 10 1
7 4 7
6 7 7 7 4 5 0 4 4 7
*/