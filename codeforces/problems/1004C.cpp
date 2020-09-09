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
using pii = pair<int, int>;
#define F first
#define S second
const int maxn = 1e5 + 5;
int arr[maxn];
pii cnt[maxn];

int32_t main() {
    int n;
    cin >> n;
    int cmp = 0, ans = 0;
    rep(i, n) {
        cin >> arr[i];
        cnt[arr[i]].F++;
        if (!cnt[arr[i]].S) cmp++;
        cnt[arr[i]].S = 1;
    }
    rep(i, n) {
        cnt[arr[i]].F--;
        if (!cnt[arr[i]].F) cmp--;
        if (cnt[arr[i]].S) ans += cmp, cnt[arr[i]].S = 0;
    }
    cout << ans << endl;
    return 0;
}