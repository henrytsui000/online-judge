#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
using ld =long double;

const int maxn = 3005;
const int half = 1505;
ld dp[maxn][half],p,ans;

int32_t main(){
    IOS;
    int n;
    cin>>n;
    dp[0][0]=1;
    rep1(i,n){
        cin>>p;
        for(int j=min(i,n/2);j>0;j--)
            dp[i][j]=(dp[i-1][j-1]*(1-p)+dp[i-1][j]*p);
        dp[i][0]=dp[i-1][0]*p;
    }

    rep(i,n/2+1)
        ans+=dp[n][i];
    cout<< fixed << setprecision(10) << ans<<endl;
    
    return 0;
}