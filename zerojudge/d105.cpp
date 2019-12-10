#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
using ll = long long;
#define ij i<<','<<j<<": "
ll n,m;
#define MAXN 30
ll dp[30][30];
ll ans=0;
int main(){
    IOS;
    cin>>n>>m;
    rep(i,n)
        rep(j,m)
            dp[i][j]=0;
    dp[0][0]=1;
    for(int j=1;j<m+1;j++){
        rep(i,n){
            dp[i][j]=dp[(i-1+n)%n][j-1]+dp[(i+1)%n][j-1];
        }
    }
    cout<<dp[0][m]<<endl;
    return 0;
}