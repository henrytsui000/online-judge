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
using ld = long double;
const ld PI = acos(-1);

int32_t main() {
    int a, chi;
    cin >> a >> chi;
    if (chi <= 180) {
        cout << "safe" << endl;
        return 0;
    }
    if (chi > 180) chi = 360 - chi;
    if (chi > 90) chi = 180 - chi;
    ld result = sin(chi * PI / 180);
    cout << int(a / result + 1e-6) << endl;
    return 0;
}
