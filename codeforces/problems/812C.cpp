#include <bits/stdc++.h>
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
#define int ll
const int maxn = 1e5 + 5;

int arr[maxn], n, p, brr[maxn];

int cal(int k) {
    rep(i, n) brr[i] = arr[i] + (i + 1) * k;
    sort(brr, brr + n);
    int cnt = 0;
    rep(i, k) cnt += brr[i];
    if (cnt <= p) return cnt;
    return 0;
}

void solve() {
    cin >> n >> p;
    rep(i, n) cin >> arr[i];
    int l = 0, r = n + 1, ans = 0;
    while (l != r - 1) {
        int mid = (l + r) >> 1;
        // cout<<mid<<' '<<cal(mid)<<endl;
        ans = cal(mid);
        if (ans)
            l = mid;
        else
            r = mid;
    }
    cout << l << ' ' << cal(l) << endl;
}

int32_t main() {
    solve();
    return 0;
}