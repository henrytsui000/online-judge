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
const int maxn = 3 * 1e5 + 5;
#define int ll
map<int, int> mp;
vector<int> vec;

bool check(string str, int cnt) {
    if (cnt >= 0) {
        int tmp = 0;
        rep(j, sz(str)) {
            if (str[j] == '(') {
                tmp++;
            } else
                tmp--;
            if (tmp < 0) return false;
        }
    } else {
        int tmp = 0;
        for (int j = sz(str) - 1; j >= 0; j--) {
            if (str[j] == ')') {
                tmp++;
            } else
                tmp--;
            if (tmp < 0) return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    rep(i, n) {
        string str;
        cin >> str;
        int cnt = 0;
        rep(j, sz(str)) if (str[j] == '(') cnt++;
        else cnt--;
        if(check(str,cnt)){
            if (!mp[cnt]) vec.eb(cnt);
            mp[cnt]++;
        }
    }
    int ans = mp[0] * mp[0];

    for (int x : vec) {
        if (x < 0) {
            ans += mp[x] * mp[-1 * x];
        }
    }
    cout << ans << endl;
}

int32_t main() {
    solve();
    return 0;
}