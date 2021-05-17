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

string toBin(int n) {
    string str = "";
    while (n) {
        str = char('0' + (n & 1)) + str;
        n >>= 1;
    }
    return str;
}

string fix(long double n) {
    string str;
    rep(i, 23) {
        n *= 2;
        str += char('0' + (n >= 1));
        if (n >= 1)
            n--;
    }
    return str;
}

void get_ans(string str) {
    str = '0' + str;
    int tmp = 0, shf = 2;
    for (int i = 0; i < sz(str); i++) {
        tmp += ((str[i] - '0') << shf), shf--;
        if (shf < 0) {
            cout << tmp;
            shf = 2, tmp = 0;
        }
    }
    cout << endl;
}

void solve() {
    string str;
    cin >> str;
    if(str == "-0")
        cout <<"20000000000"<<endl;
    else if(str == "0")
        cout <<"00000000000"<<endl;
    int n = stoi(str);
    int si = (n < 0), e;
    if (n < 0) n *= -1;
    while (n > (1 << e))
        e++;
    long double f = (long double)n / (1 << (e - 1)) - 1;
    string ans = char('0' + si) + toBin(e + 126) + fix(f);
    get_ans(ans);
}

int32_t main() {
    int t;
    cin >> t;
    rep(i, t)
        solve();
    return 0;
}
