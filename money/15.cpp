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
vector<int> vec;

void init() {
    vec.eb(1), vec.eb(1);
    for (int i = 1; i < 60; i++)
        vec.eb(vec[i] + vec[i - 1]);
    reverse(all(vec));
    vec.pop_back();
}

void solve(int n) {
    bool key = false;
    for (int x : vec) {
        if (key || n / x) {
            cout << n / x;
            n %= x;
            key = true;
        }
    }
    cout << endl;
}

int32_t main() {
    string n;
    IOS;
    init();
    while (cin >> n && n != ".") {
        solve(stoll(n));
    }
    return 0;
}