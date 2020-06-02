#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int maxn = 10005;
int arr[maxn];
int32_t main(){
    int n;cin>>n;
    rep(i,n)
        cin>>arr[i];
    int r=0;
    for(int i=0;i<n;i+=arr[n-1]){
        r+=arr[i],r%=n;
    }
    if(!r)cout<<n;
    else cout<<r;
    cout<<' '<<arr[(r-1+n)%n]<<endl;
    return 0;
}