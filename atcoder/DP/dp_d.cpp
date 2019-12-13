#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
const int maxn = 105;
const int maxw = 1e5 + 5 ;
#define int long long
int dp[maxn][maxw];
int arr[2][maxn];
int32_t main(){
    IOS;
    int n,w;
    cin>>n>>w;
    rep(i,n)
        rep(j,2)
            cin>>arr[j][i];
    memset(dp,0,sizeof(dp));
    for(int i=arr[0][0];i<=w;i++)
        dp[0][i]=arr[1][0];
    int sit=0;
    rep1(i,n){
        rep(j,w+1){
            if(j-arr[0][i]>=0)
                dp[sit^1][j]=max(dp[sit][j],dp[sit][j-arr[0][i]]+arr[1][i]);
            else
                dp[sit^1][j]=dp[sit][j];
        }
        sit^=1;
    }
    cout<<max(dp[sit][w],dp[sit^1][w])<<endl;
    
    return 0;
}