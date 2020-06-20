#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define eb emplace_back
#define int ll
const int maxn = 2*1e5+5;
int arr[maxn];
int dp[4][maxn];

int32_t main(){
    int n;cin>>n;
    rep(i,n){
        int a;cin>>a;
        if(a>0) arr[i]=1;
    }
    rep1(i,n){
        if(arr[i-1]){
            dp[0][i]=dp[0][i-1]+1;
            dp[1][i]=dp[0][i-1]+dp[1][i-1];
            dp[2][i]=dp[2][i-1];
            dp[3][i]=dp[2][i-1]+dp[3][i-1];
        }else{
            dp[0][i]=dp[2][i-1];
            dp[1][i]=dp[1][i-1]+dp[0][i-1];
            dp[2][i]=dp[0][i-1]+1;
            dp[3][i]=dp[2][i-1]+dp[3][i-1];
        }
    }
    cout<<dp[2][n]+dp[3][n]<<' '<<dp[0][n]+dp[1][n]<<endl;
    return 0;
}