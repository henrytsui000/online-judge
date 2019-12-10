#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define MAXN 200000+5
int main(){
    #define int long long
    IOS;
    int a,dp[MAXN],q,l,r,n;
    cin>>n;
    memset(dp,0,sizeof(dp));
    rep(i,n){
        cin>>a;
        dp[i+1]=dp[i]+a;
    }
    cin>>q;
    rep(i,q){
        cin>>l>>r;
        cout<<dp[r]-dp[l-1]<<endl;
    }


    return 0;
}