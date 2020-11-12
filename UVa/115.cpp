#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int maxn = 1e3+5;
int arr[maxn]; 
int dp[maxn];

int32_t main(){
    int n;
    while(cin>>n){
        rep(i,n)
            cin>>arr[i];
        rep(i,n)
            dp[i] = 1;
        for(int i = 0; i < n ; i++){
            for(int j = i-1 ; j >= 0 ; j --){
                if(arr[i]>arr[j])
                    dp[i] = max(dp[i],dp[j]+1);
            }
        }
        int ans = 0;
        rep(i,n)
            ans = max(ans,dp[i]);
        cout<<ans<<endl;
    }
    return 0;
}