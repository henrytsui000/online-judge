#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define MAXN 45
using ll = long long;
ll dp[MAXN][5];
int main(){
    IOS;
    ll T;cin>>T;
    rep(i,MAXN)
        rep(j,5)
            dp[i][j]=0;
    rep(i,5)
        dp[2][i]=1;
    dp[1][4]=1;
    for(ll i=2;i<MAXN;i++){
        dp[i][0]=dp[i-1][3]+dp[i-1][4];
        dp[i][1]=dp[i-1][2]+dp[i-1][4];
        dp[i][2]=dp[i-1][4];
        dp[i][3]=dp[i-1][4];
        dp[i][4]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3]+dp[i-1][4];
    }
    while(T--){
        ll n;
        cin>>n;
        ll ans=0;
        rep(i,5)
            ans+=dp[n][i];
        cout<<ans<<endl;
    }
    return 0;
}