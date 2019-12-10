#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_withh_stdio(0);cin.tie(0)
#define endl '\n'
#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define maxn 120005
ll dp[7][maxn];
#define mod 100000007
int main(){
    memset(dp,0,sizeof(dp));
    int n;
    cin>>n;
    dp[0][0]=1;
    dp[1][0]=1;
    dp[3][0]=1;
    for(int i=1;i<n;i++){
        dp[0][i]=dp[0][i-1]+dp[1][i-1]+dp[2][i-1];
        dp[0][i]%=mod;
        dp[1][i]=dp[0][i-1];
        dp[2][i]=dp[1][i-1];
        dp[3][i]=dp[0][i-1]+dp[1][i-1]+dp[2][i-1];
        dp[3][i]%=mod;
        dp[4][i]=dp[4][i-1]+dp[3][i-1]+dp[5][i-1]+dp[6][i-1];
        dp[4][i]%=mod;
        dp[5][i]=dp[4][i-1]+dp[3][i-1];
        dp[5][i]%=mod;
        dp[6][i]=dp[5][i-1];
    }
    ll ans=0;
    rep(i,7)
        ans+=dp[i][n-1];
    cout<<ans%mod<<endl;


    return 0;
}