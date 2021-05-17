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
const int maxn = 1e4 + 5;
int arr[maxn];
int dp[maxn];
vector<vector<int> > vec;
vector<int> tmp;
void goback_goback(int sit) {
    if (dp[sit] == 1)
        vec.eb(tmp);
    else
        for (int i = sit - 1; i >= 0; i--) {
            if (dp[i] == dp[sit] - 1 && arr[i] < arr[sit]) {
                tmp.eb(arr[i]);
                goback_goback(i);
                tmp.pop_back();
            }
        }
}

void solve() {
    int n;
    cin >> n;
    rep(i, n)
        cin >> arr[i];
    rep(i, n)
        dp[i] = 1;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    arr[n] = 1e9, dp[n] = ans + 1;
    goback_goback(n);
    cout << sz(vec) << endl;
    for (auto x : vec) {
        reverse(all(x));
        for (int t : x)
            cout << t << ' ';
        cout << endl;
    }
    vec.clear();
}

int32_t main() {
    IOS;
    int n;
    cin >> n;
    rep(i, n) {
        solve();
    }
    return 0;
}