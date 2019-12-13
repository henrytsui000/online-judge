#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
const int maxn = 3005;
using ll = long long;
ll s[maxn],dp[maxn][maxn],arr[maxn];
#define int ll



int32_t main(){
    IOS;
    int n;
    cin>>n;
    rep(i,n)
        cin>>arr[i];
    s[0]=arr[0];
    
    rep1(i,n)
        s[i]=arr[i]+s[i-1];
    
    rep(i,n)
        dp[i][i]=arr[i];
    
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            dp[j][i]=max(
                s[i]-s[j]-dp[j+1][i]+arr[j],
                s[i-1]-s[j-1]-dp[j][i-1]+arr[i]
            );
        }
    }
    cout<<dp[0][n-1]-s[n-1]+dp[0][n-1]<<endl;


    return 0;
}