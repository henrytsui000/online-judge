#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define in(a) cout<<"in la->"<<a<<endl

const int maxn = 100+5;
const int maxk = 1e5+5;
const int mod = 1e9+7;
int dp[maxn][maxk];
int arr[maxn];


int32_t main(){
    int n,k;
    cin>>n>>k;
    rep1(i,n)
        cin>>arr[i];
    rep(i,n+1)
        dp[i][0]=0;
    rep(i,k)
        dp[1][i]=1;
    
    // rep(i,n+1){
    //     rep(j,k+1){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            rep(x,arr[i]){
                if(j-x>=0)
                    dp[i][j]+=dp[i-1][j-x];
                dp[i][j]%=mod;
            }
        }
    }
    // rep(i,n+1){
    //     rep(j,k+1){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n][k];
    return 0;
}