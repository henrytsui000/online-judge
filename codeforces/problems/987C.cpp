#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int inf = 0x3f3f3f3f;
const int maxn = 3005;
int arr[maxn];
int c[maxn];
int dp[maxn];

void solve(){
    IOS;
    int n;
    memset(dp,inf,sizeof(dp));
    cin>>n;
    rep(i,n)
        cin>>arr[i];
    rep(i,n)
        cin>>c[i];
    rep(i,n){
        rep(j,i) if(arr[i]>arr[j])
            dp[i]=min(dp[i],c[j]);
        dp[i]+=c[i];
    }
    int ans=inf;
    rep(i,n){
        rep(j,i) if(arr[i]>arr[j])
            ans=min(dp[j]+c[i],ans);
    }
    cout<<(ans==inf?-1:ans)<<endl;
    return ;
}

int32_t main(){
    IOS;
    solve();
    return 0;
}