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
vector<int> vec;

void solve() {
    int n, m;
    cin >> n >> m;
    rep(i, n * m) {
        int a;
        cin >> a;
        vec.eb(a);
    }
    sort(all(vec));
    for (int x : vec)
        cout << x << ' ';
    cout << endl;
    vec.clear();
}

int32_t main() {
    int n;
    IOS;
    cin >> n;
    rep(i, n)
        solve();
    return 0;
}