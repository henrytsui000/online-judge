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
const int maxn = 4 * 1e5 + 5;

void solve() {
    IOS;
    int n;
    cin >> n;
    vector<int> cnt;
    vector<int> vec;
    int crt = 1;
    rep(i, n) {
        int a;
        cin >> a;
        vec.eb(a);
    }
    vec.eb(-1);
    int mx = 0;
    for (int i = 0, ii = 1; ii < sz(vec); i++, ii++)
        if (vec[i] != vec[ii]) {
            cnt.eb(ii);
            if (ii <= n / 2) mx = max(ii, mx);
        }
    int sil = 0, x = 1, brz = 0;
    for (x = 1; x < sz(cnt); x++) {
        sil += (cnt[x] - cnt[x - 1]);
        if (sil > cnt[0]) break;
    }
    x++;
    for (x; x < sz(cnt); x++) {
        if (sil + cnt[0] + brz + (cnt[x] - cnt[x - 1]) > n / 2) break;
        brz += (cnt[x] - cnt[x - 1]);
    }
    if (brz > cnt[0] && sil > cnt[0])
        cout << cnt[0] << ' ' << sil << ' ' << brz << endl;
    else
        cout << "0 0 0" << endl;
}

int32_t main() {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}