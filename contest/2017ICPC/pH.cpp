#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<(int)n;i++)
#define int ll
using ll = long long;
using pii = pair<int,int>;
#define X first
#define Y second 
#define SZ(a) ((int)a.size())
#define all(a) (a.begin(),a.end())
#define eb emplace_back
#define pb push_back
int32_t main(){
    int arr[6];
    int ans = 0;

    rep(i,6)
        cin>>arr[i];
    rep(i,3)
        ans += max((arr[i+3] - arr[i]), (ll)0);
    cout<<ans<<endl;
    return 0;
}