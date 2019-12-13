#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define maxn 100000
int dp[3][maxn];
int arr[3][maxn];
int main(){
    IOS;
    int n;
    cin>>n;
    rep(i,n)
        rep(j,3)
            cin>>arr[j][i];
    rep(i,3)
        dp[i][0]=arr[i][0];
    rep1(i,n){
        dp[0][i]=max(dp[1][i-1],dp[2][i-1]);
        dp[1][i]=max(dp[0][i-1],dp[2][i-1]);
        dp[2][i]=max(dp[0][i-1],dp[1][i-1]);
        rep(j,3)
            dp[j][i]+=arr[j][i];
    }
    cout<<max({dp[0][n-1],dp[1][n-1],dp[2][n-1]})<<endl;
    return 0;
}