#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
bool big(int n) {
    while (n / 10) {
        if (n % 10 > (n / 10) % 10)
            return false;
        n /= 10;
    }
    return true;
}

bool check(int a, int b) {
    vector<int> v_a;
    vector<int> v_b;
    while (a) {
        v_a.emplace_back(a % 10);
        v_b.emplace_back(b % 10);
        a /= 10, b /= 10;
    }
    sort(all(v_a));
    sort(all(v_b));
    rep(i, sz(v_a)) if (v_a[i] != v_b[i]) return false;
    return true;
}

void solve() {
    string str;
    while (cin >> str && str != "-1") {
        vector<int> vec;
        bool key = false;
        for (int i = sz(str) - 1; i > 0; i--){
            vec.emplace_back(str[i] - '0');
            if (str[i] > str[i - 1]) {
                vec.emplace_back(str[i] - '0');
                vec.emplace_back(str[i - 1] - '0');
                rep(j, i - 1) cout << str[j];
                sort(all(vec));
                rep(j, sz(vec)) if (vec[j] > str[i - 1] - '0') {
                    cout << vec[j];
                    vec.erase(vec.begin() + j);
                    break;
                }
                for (int x : vec)
                    cout << x;
                cout << endl;
                key = true;
                break;
            }
        }
        if(!key)
            cout << str<<endl;
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