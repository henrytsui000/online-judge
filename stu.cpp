#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define eb emplace_back
const int maxn = 1e5+5;
int arr[maxn];
int dp[maxn];
int32_t main(){
    int n,k;
    cin>>n>>k;
    k++;
    rep(i,n) cin>>arr[i];
    rep1(i,k)
        dp[i]=max(dp[i-1],arr[i]);
    rep(i,n) if(i-k>=0)
            dp[i]=max(dp[i-k]+arr[i],dp[i-1]);
    cout<<dp[n-1]<<endl;
    return 0;
}