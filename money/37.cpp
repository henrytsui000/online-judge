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
#define num(a) (a <= '9' && a >= '0')
const int maxn = 1e5 + 5;

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

string count(string str, int a, int b) {
    if (str == "*")
        return itos(a * b);
    else if (str == "+")
        return itos(a + b);
    else if (str == "-")
        return itos(a - b);
    else if (str == "/")
        return itos(a / b);
    else if (str == "%")
        return itos(a % b);
    else {
        return "-1";
    }
}

void solve(string str) {
    str += ' ';
    string tmp = "";
    vector<string> vec;
    rep(i, sz(str)) {
        if (str[i] == ' ') {
            vec.eb(tmp);
            tmp = "";
        } else {
            tmp += str[i];
        }
    }
    vector<string> cal;
    if (sz(vec) < 3) {
        cout << "illegal" << endl;
        return;
    }
    cal.eb(vec[0]);
    cal.eb(vec[1]);
    int use = 2;
    while (sz(cal) != 1) {
        if (sz(cal) > 2 && num(cal[sz(cal) - 1][0]) && num(cal[sz(cal) - 2][0])) {
            string k = count(cal[sz(cal) - 3], stoi(cal[sz(cal) - 2]), stoi(cal[sz(cal) - 1]));
            cal.pop_back();
            cal.pop_back();
            cal.pop_back();
            if (k == "-1") {
                cout << "illegal" << endl;
                return;
            } else
                cal.eb(k);
        } else {
            if (use == sz(vec)) {
                cout << "illegal" << endl;
                return;
            }
            cal.eb(vec[use++]);
        }
    }
    cout << cal[0] << endl;
}

int32_t main() {
    string str;
    while (getline(cin, str) && str != ".") {
        solve(str);
    }
    return 0;
}