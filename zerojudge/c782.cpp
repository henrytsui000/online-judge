#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define mem(a,b) memset(a, (b), sizeof(a))
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int maxn = 2000005;

#define int ll

int arr[maxn];
int dp[maxn];
int c[maxn];

int32_t main(){
    IOS;
    int t;
    cin>>t;
    while(t--){

        int n,k;cin>>n>>k;
        rep(i,n)
            cin>>arr[i];
        rep(i,n){
            cin>>dp[i];
            c[i]=dp[i];
        }
        dp[n]=0;
        for(int i=n-1;i>=0;i--)
            dp[i]+=dp[i+1];
            
        ll ans=0,itr=0;
        rep(i,n){
            while((arr[itr]<=arr[i]+k)&&(itr<n))itr++;
            if(itr>=n) break;
            ans+=(dp[itr]*c[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}


