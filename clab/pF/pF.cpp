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
const int maxn = 1e5 + 5;

int32_t main() {
    int n, cnt = 0;
    int mx = 0;
    for (int i = 1; i < 500; i++) {
        cnt = 0;
        n = i;
        for (; n != 1; cnt++, n = (n % 2 ? n * 3 + 1 : n / 2));
        // cout << cnt << endl;
        if (cnt > mx) {
            cout << i << ' ' << cnt << endl;
            mx = cnt;
        }
    }
    // cin >> n;
    return 0;
}