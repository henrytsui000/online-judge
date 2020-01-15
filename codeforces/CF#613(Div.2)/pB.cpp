#include<bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define pb emplace_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
using ll = long long;
using pii = pair<int,int>;
const int maxn =100050;
ll dp[maxn];
ll arr[maxn];
int32_t main(){
    IOS;
    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        ll sum=0;
        bool key2=false,key=false;
        rep(i,n){
            cin>>arr[i];
            sum+=arr[i];
            dp[i+1]=dp[i]+arr[i];
            if(dp[i+1]<=0)
                dp[i+1]=0,key2=true;
        }
        rep1(i,n-1)
            if(dp[i]>=sum)
                key=1;
        if(key2&&sum<=dp[n])
            cout<<"NO"<<endl;
        else if(key)
            cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
/*
3
4
1 2 3 4
3
7 4 -1
3
5 -5 5
*/