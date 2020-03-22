#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define in cout<<"in lar"<<endl
const int INF=0x3f3f3f3f;

const int maxn = 1e5+5;
ll dp[maxn],arr[maxn],dp2[maxn];

int32_t main(){
    IOS;
    ll n,k,ans=0;
    while(cin>>n>>k){
        k--;
        rep(i,n){
            cin>>arr[i];
            dp[i]=dp[i-1]+arr[i];
        }
        dp2[0]=arr[n-1];
        rep1(i,n-1)
            dp2[i]=arr[n-i-1]+dp2[i-1];
        rep(i,n){
            if(i-k>=0)
                ans=max(ans,dp[i]-dp[i-k-1]);
            else
                ans=max(ans,dp[i]+dp2[k-i-1]);
        }
        cout<<ans<<endl;
        ans=0;
        memset(dp,0,sizeof(dp));
        memset(dp2,0,sizeof(dp2));
    }
    
    return 0;
}
/*
5 2
1 2 3 4 5
*/