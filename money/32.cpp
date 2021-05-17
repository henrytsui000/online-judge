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
const int maxn = 1005;
int arr[maxn][maxn];
int deep[maxn];

void gogo(int nd, int n) {
    rep(i, n) {
        if (arr[nd][i] != -1) {
            if (arr[nd][i] + deep[nd] < deep[i]) {
                deep[i] = arr[nd][i] + deep[nd];
                gogo(i, n);
            }
        }
    }
}

void solve(int n) {
    memset(deep, 0x3f3f3f3f, sizeof(deep));
    rep(i, n) {
        rep(j, n) {
            cin >> arr[i][j];
        }
    }
    deep[0] = 0;
    gogo(0, n);
    cout << deep[n - 1] << endl;
}

int32_t main() {
    int n;
    while (cin >> n) {
        solve(n);
    }
    return 0;
}