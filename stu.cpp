#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int maxn = 1e5+5;

int32_t main(){
    int n;
    cin>>n;
    int arr[n];
    rep(i,n)
        cin>>arr[i];
    int dp[n][n];
    memset(dp,10000,sizeof(dp));
    rep(i,n)
        dp[i][i]=arr[i];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=i;k<=j;k++){
                dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
            }
        }
    }
    rep(i,n){
        rep(j,n)
            cout<<dp[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
