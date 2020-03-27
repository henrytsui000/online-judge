#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int maxn = 1e6+5;
#define int unsigned long long
int dp[maxn];
int arr[maxn];

int32_t main(){
    IOS;
    int n;
    while(cin>>n){
        int sum=0;
        memset(dp,0,sizeof(dp));
        rep(i,n){
            cin>>arr[i];
            sum+=arr[i];
        }
        rep(i,n){
            sum-=arr[i];
            dp[i]=sum;
        }
        // rep(i,n)
        //     cout<<dp[i]<<' ';
        // cout<<endl;
        ll ans=0;
        rep(i,n){
            ans+=arr[i]*dp[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}