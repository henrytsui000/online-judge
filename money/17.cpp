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
#define mp make_pair
#define F first
#define S second
const int maxn = 1e5 + 5;
using pdii = pair<double, pair<int, int> >;

void solve(int n) {
    vector<pdii> vec;
    for (int i = 0; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            vec.eb(mp((double)i / j, mp(i / __gcd(i, j), j / __gcd(i, j))));
        }
    }
    sort(all(vec));
    pdii tmp;
    vector<pdii> ans;
    for (pdii x : vec) {
        if (x != tmp) {
            ans.eb(x);
        }
        tmp = x;
    }
    cout << sz(ans) + 1<<" terms" << endl;
    for (pdii x : ans) {
        cout << x.S.F << '/' << x.S.S << ' ';
    }
    cout <<"1/1"<< endl<<endl;
}

int32_t main() {
    string n;
    IOS;
    while (cin >> n && n != ".") {
        solve(stoll(n));
    }
    return 0;
}