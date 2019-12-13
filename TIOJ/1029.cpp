#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define maxn 1005
int sum[maxn],arr[maxn],dp[maxn][maxn];

int32_t main(){
    int n;
    cin>>n;
    memset(sum,0,sizeof(sum));
    memset(dp,0,sizeof(dp));
    rep(i,n)
        cin>>arr[i];
    sum[0]=arr[0];
    rep1(i,n)
        sum[i]=sum[i-1]+arr[i];
        
    rep(i,n)
        dp[i][i]=arr[i];
    for(int i=1;i<n;i++)
        for(int j=i-1;j>=0;j--){
            dp[j][i] = max(
                sum[i]  -sum[j]  -dp[j+1][i]+arr[j] ,
                sum[i-1]-sum[j-1]-dp[j][i-1]+arr[i] );
        }
    cout<<dp[0][n-1]<<' '<<sum[n-1]-dp[0][n-1]<<endl;
    return 0;
}
/*
input
6
4 7 2 9 5 2
output
18 11
*/