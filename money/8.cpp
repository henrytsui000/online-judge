
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define sz(a) ((int)a.size())
// #define int long long
int ans = 0;
using pii = pair<int,int>;
vector<pii> vec;
void gogo(int dep, int p) {
    if (dep == sz(vec)) {
        ans += p;
        return;
    }
    rep(i, vec[dep].second + 1) {
        int k = vec[dep].first;
        gogo(dep + 1, p * (pow(k, i)));
    }
}

void solve() {
    int n;
    while (cin >> n && n != -1) {
        vec.clear();
        int itr = 2, cnt = 0, p = 1;
        ans = 0;
        while (n != 1) {
            if (n % itr == 0) {
                cnt++;
                n /= itr;
            } else if (cnt) {
                vec.emplace_back(make_pair(itr, cnt));
                p *= (cnt + 1);
                cnt = 0;
                itr++;
            }else itr++;
        }
        vec.emplace_back(make_pair(itr, cnt));
        p *= (cnt + 1);
        for (pair<int, int> x : vec)
            cout << "(" << x.first << "," << x.second << ")";
        cout << endl;
        cout << p << endl;
        gogo(0, 1);
        cout << ans << endl;
        cout << "==" << endl;
    }
}

int32_t main() {
    // rep(i, 10) {
    // fout << "case " << i + 1 << ":\n";
    solve();
    // cout << "==" << endl;
    // }
    return 0;
}