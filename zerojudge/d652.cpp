#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define MAXN 50
#define INF 1e18
using ll = long long;
#define ij i<<','<<j<<": "
ll a[MAXN],dp[MAXN][MAXN];
int main(){
    int n;cin>>n;
    rep(i,n)
        cin>>a[i];
    rep(i,n)
        rep(j,n)
            dp[i][j]=INF;
    rep(i,n){
        dp[i][i]=0;
        if(i==0)
            dp[i][i+1]=
    }
        dp[i][i]=dp[i][i+1]=0;
    for(int k=2;k+2<n;k++){
        for(int i=0;i+k<n;i++){
            for(int j=0;j+2<=i+k;j++)
                dp[i][i+k]=min(dp[i][i+j]+dp[i+j+2][i+k]+a[i+j]*a[i+j+1]*a[i+j+2],dp[i][i+k]);
        }
    }
    rep(i,n){
        rep(j,n)
            cout<<ij<<dp[i][j]<<endl;
        cout<<endl;

    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}