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
    vector<int> vec;
    string tmp = "";
    bool key = false;
    int tot = 0;
    for (int i = 1; i < sz(str); i++) {
        if (str[i] <= '9' && str[i] >= '0')
            tmp += str[i];
        else {
            vec.emplace_back(stoi(tmp)), tot += (stoi(tmp)), tmp = "";
        }
    }
    for (int i = 0; i < (1 << sz(vec)); i++) {
        int tmt = i, cnt = 0;
        for (int j = 0; (1 << j) <= i; j++)
            cnt += (vec[j] * ((i >> j) & 1));
        if (cnt * 2 == tot) {
            cout <<"{";
            for (int j = 0; (1 << j) <= i; j++)
                if ((i >> j) & 1)
                    cout << vec[j] << ' ';
            cout <<"}"<< endl;
            key = true;
        }
    }
    if(!key) cout << "No such subset"<<endl;
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