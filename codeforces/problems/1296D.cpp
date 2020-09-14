#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
using ll = long long;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define endl '\n'
#define all(a) a.begin(), a.end()
#define sz(a) ((int)a.size())
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define eb emplace_back
const int maxn = 2*1e5 + 5;
int arr[maxn];

void solve() {
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    rep(i, n) cin >> arr[i];
    rep(i, n) {
        int tmp = arr[i] % (a + b);
        if (!tmp) tmp = a + b;
        if (tmp <= a)
            arr[i] = 0;
        else
            arr[i] = ((tmp - 1) / a);
    }
    sort(arr, arr + n);
    int ans = 0;
    rep(i, n) {
        k -= arr[i];
        if (k < 0) break;
        ans++;
    }
    cout<<ans<<endl;
    return;
}

int32_t main() {
    IOS;
    solve();
    return 0;
}