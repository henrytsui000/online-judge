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
#define int ll

vector<int> vec;
void init() {
    int cnt = 0, crt = 0, sit = 0;
    for (int i = 1; i < 100000; i++) {
        if (i == pow(10, cnt))
            cnt++;
        crt += cnt;
        sit += crt;
        vec.eb(sit);
    }
    // for(int x: vec)
    //     cout << x << ' ';
    // cout << endl;
}

string itos(int k) {
    string tmp;
    while (k) {
        tmp += (k % 10 + '0');
        k /= 10;
    }
    string ret;
    for (int i = 0; i < sz(tmp); i++)
        ret += tmp[sz(tmp) - i - 1];
    return ret;
}

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    int s = lower_bound(all(vec), n) - vec.begin();
    n -= vec[s - 1];
    string str = "";
    for (int i = 1;; i++) {
        str += itos(i);
        if (sz(str) > n) {
            cout << str[n - 1] << endl;
            return;
        }
    }
}

int32_t main() {
    int n;
    cin >> n;
    init();
    rep(i, n) {
        cout << "Case " << i + 1 << ": ";
        solve();
    }
    return 0;
}