#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int maxn = 1e5+5;

int arr[2005];
int32_t main(){
    int n, d;
    cin>>n>>d;
    rep(i,n)
        cin>>arr[i];
    int cnt =0;
    rep(i,n)
        cnt+=(arr[i]/10);
    sort(arr, arr+n);
    
    return 0;
}