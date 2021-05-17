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

void solve() {
    int n, k, d, a;
    cin >> n >> k >> d;
    map<int, int> dp[65];
    set<int> lst;
    vector<int> vec(n);
    dp[0][0] = 1, lst.insert(0);
    rep(i, n) cin >> vec[i];
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--)
            for (int tmp : lst)
                dp[j + 1][(tmp + vec[i]) % d] += dp[j][tmp];
        set<int> crt;
        for (int tmp : lst) crt.insert((tmp + vec[i]) % d);
        for (int tmp : crt) lst.insert(tmp);
    }
    cout << dp[k][0] << endl;
}

int32_t main() {
    IOS;
    int n;
    cin >> n;
    rep(i, n) {
        cout << "Case " << i + 1 << ": ";
        solve();
    }
    return 0;
}