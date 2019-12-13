#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<=n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
const int maxn = 10005;
#define ine long long
int dp[maxn],g[maxn];
int h,w;
const int mod = 1e9+7;
void gogo(){
    rep1(i,w){
        if(g[i]!=-1){
            if(dp[i]==-1)
                dp[i]=0;
            if(dp[i-1]!=-1){
                dp[i]+=dp[i-1];
                dp[i]%=mod;
            }
        }else{
            dp[i]=-1;
        }
    }
}

int32_t main(){
    IOS;
    cin>>h>>w;
    memset(dp,0,sizeof(dp));
    dp[1]=1;
    rep1(i,h){
        string str;
        cin>>str;
        rep1(j,w){
            if(str[j-1]=='#'){
                g[j]=-1;
            }
        }
        gogo();
        memset(g,0,sizeof(g));
    }
    cout<<dp[w]<<endl;
    return 0;
}