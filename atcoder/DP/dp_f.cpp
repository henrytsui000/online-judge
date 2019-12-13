#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define maxn 3005

int dp[maxn][maxn];
string s,t;

void bt(int x,int y,int r){
    if(!r)
    return ;
    if(dp[x-1][y]==r)
        bt(x-1,y,r);
    else if(dp[x][y-1]==r)
        bt(x,y-1,r);
    else{
        bt(x-1,y-1,r-1);
        cout<<s[x-1];
    }
}

int32_t main(){
    IOS;
    cin>>s>>t;
    int ss=s.size(),st=t.size();
    memset(dp,0,sizeof(dp));
    rep1(i,ss)
        rep1(j,st)
            if(s[i-1]==t[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    bt(ss,st,dp[ss][st]);
    return 0;
}