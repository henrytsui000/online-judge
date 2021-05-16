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

void solve(string str) {
    cout << "For s=" << str << ", the substrings are" << endl;
    for (int i = 0; i < (1 << sz(str)); i++) {
        cout << "\"";
        for (int j = 0; (1 << j) <= i; j++)
            if ((i >> j) & 1)
                cout << str[j];
        cout << "\" ";
    }
    cout << endl;
}

int32_t main() {
    string str;
    while (getline(cin, str)) {
        if (str == ".")
            break;
        solve(str);
    }
    return 0;
}