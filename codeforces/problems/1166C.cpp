#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < (int)n; i ++)
const int maxn = 2e5 +5;
int arr[maxn];
void solve(){
    int n;
    cin >> n;
    rep(i,n)
        cin >> arr[i];
    rep(i,n)
        arr[i] = abs(arr[i]);
    sort(arr, arr + n);
    long long ans = 0;
    for(int i = 0 ; i < n ; i ++){
        ans += (i - (lower_bound(arr , arr +n , (arr[i]+1) /2) - arr));
    }
    cout << ans << endl;
}

int main(){
    solve();
    return 0;
}