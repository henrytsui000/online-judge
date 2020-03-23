#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define int  long long
const int maxn = 1e5+5;
const int mod = 1e9+7;
int dp[maxn];
int32_t main(){
    int n,m;
    cin>>n>>m;
    rep(i,3)
        dp[i]=1;
    for(int i=3;i<n+5;i++)
        dp[i]=dp[i-1]+dp[i-3];
    int ans=1,arr[m+2];
    arr[0]=0;
    rep1(i,m)
        cin>>arr[i];
    arr[m+1]=n;
    rep1(i,m+1){
        ans*=dp[arr[i]-arr[i-1]];
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}