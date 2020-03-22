#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
using ll = long long;
using pii =pair<int,int>;
#define S second
#define F first
int main(){
    IOS;
    int n;
    cin>>n;
    int dp[n+1][105];
    memset(dp,0,sizeof(dp));
    pii p;
    for(int i=1;i<=n;i++){
        cin>>p.F>>p.S;
        rep(j,105){
            if(j-p.F>=0)
                dp[i][j]=max(
                    dp[i-1][j],dp[i-1][j-p.F]+p.S
                );
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][100]<<endl;

    return 0;
}