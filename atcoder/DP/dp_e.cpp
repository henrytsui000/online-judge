#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);
using ll = long long;
const int maxn = 105;
const int maxm = 1e5+5;
const int us = 1e5+4;
int n,w;
int arr[maxn][2];
ll dp[maxm];
const ll inf = 0x3f3f3f3f3f3f3f3f;
int32_t main(){
    IOS;
    cin>>n>>w;
    rep(i,maxm)
        dp[i]=inf;
    dp[0]=0;
    rep1(i,n)
        rep(j,2)
            cin>>arr[i][j];
    rep1(i,n){
        for(int j=us;j>=arr[i][1];j--)
            dp[j]=min(dp[j],dp[j-arr[i][1]]+arr[i][0]);
        // for(int j=us-1;j>=0;j--)
        //     dp[j]=min(dp[j],dp[j+1]);
    }
    ll ans=0;
    for(int i=us;i>=0;i--){
        if(dp[i]<=w&&dp[i]!=inf){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
/*
3 8
3 3
4 5
5 6
*/