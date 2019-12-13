#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define int long long
using ll = long long;

const int maxn = 405;
ll arr[maxn];
ll dp[maxn][maxn];
ll sum[maxn];

int32_t main(){
    IOS;
    int n;
    cin>>n;
    rep(i,n)
        cin>>arr[i];
    memset(sum,0,sizeof(sum));
    rep(i,n)
        dp[i][i]=0;
    rep1(i,n+1)
        sum[i]=sum[i-1]+arr[i-1];
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            dp[j][i]=1e18;
            for(int k=j;k<i;k++){
                dp[j][i]=min(dp[j][i],dp[j][k]+dp[k+1][i]);
            }
            dp[j][i]+=(sum[i+1]-sum[j]);
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}