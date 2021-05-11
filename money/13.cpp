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
vector<double> vec;
double range(int a, int b) {
    double cnt = 0;
    for (int i = a; i <= b; i++) {
        cnt += vec[i];
    }
    return cnt;
}

void solve() {
    string str;
    double ans = 0;
    int l = 0, r = 0, cnt = 0;
    double mx = 0;
    vec.clear();
    while (cin >> str) {
        if (str == "]") {
            cout <<"Sum of A["<< l <<"..."<<r<<"] is max, which sum is "<<mx<<endl;
            return;
        } else {
            vec.eb(stod(str));
            rep(i, sz(vec)) {
                rep(j, i) {
                    if (range(j, i) > mx) {
                        l = j, r = i;
                        mx = range(j, i);
                    }
                }
            }
        }
    }
}

int32_t main() {
    IOS;
    char ch;
    while (cin >> ch) {
        if (ch == '.')
            break;
        else
            solve();
    }
    return 0;
}