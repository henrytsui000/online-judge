#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
const int maxn = 1000;
#define int long long
using ll =long long;

int dp[maxn][maxn];
int32_t main(){
    int n;
    cin>>n;
    rep(i,n)
        dp[i][0]=dp[0][i]=1;
    rep1(i,n){
        rep1(j,n){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    rep(i,n){
        rep(j,n){
            if(dp[i][j]<10)
                cout<<" ";
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}
/*
go to a,b-> (a+b)!/a!b!
*/