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
#define ture true
map<char, int> mp;
bool solve(string str) {
    int cnt = 0;
    rep(i, sz(str)) {
        cnt += mp[str[i]];
        if (cnt < 0) {
            return false;
        }
    }
    if (cnt > 0)
        return false;
    else
        return ture;
}

int32_t main() {
    string str;
    mp['('] = 1;
    mp[')'] = -1;
    while (cin >> str && str != ".") {
        cout << "This string of parentheses is" << (solve(str) ? " " : " not ") << "well-balanced !\n";
    }
    return 0;
}