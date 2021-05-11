#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define sz(a) ((int)a.size())
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define endl '\n'
#define all(a) a.begin(), a.end()
void solve() {
    char ch;
    cin >> ch;
    vector<int> vec;
    int a;
    while (cin >> a && a != -1)
        vec.emplace_back(a);
    if (ch == 'A') {
        for (int i = 0; i < sz(vec); i++) {
            int cnt = 0;
            rep(j, i) {
                if (vec[j] < vec[i]) {
                    cnt++;
                }
            }
            cout << cnt << ' ';
        }
        cout << endl;
    } else {
        vector<int> ans(sz(vec));
        int crt = 0;
        rep(k, sz(vec)) {
            for (int i = sz(vec) - 1; i >= 0; i--) {
                if (vec[i] == 0) {
                    ans[i] = crt++;
                    for (int j = i; j < sz(vec); j++)
                        vec[j]--;
                    break;
                }
            }
        }
        for (int x : ans)
            cout << x << ' ';
        cout << endl;
    }
}

int32_t main() {
    int n;
    IOS;
    cin >> n;
    rep(i, n) {
        // fout << "case " << i + 1 << ":\n";
        solve();
        // cout << "==" << endl;
    }
    return 0;
}