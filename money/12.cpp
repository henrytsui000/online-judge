#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define int ll
const int maxn = 15;
int arr[maxn + 5];
void init() {
    arr[0] = 1;
    rep(i, maxn)
        arr[i + 1] = (i + 1) * arr[i];
}

void solve(int n) {
    bool key = false;
    for (int i = 15; i >= 0; i--) {
        if (key || (n / arr[i])) {
            cout << (n / arr[i]) << ' ';
            key = true, n %= arr[i];
        }
    }
    cout << endl;
}

int32_t main() {
    int n;
    init();
    while (cin >> n && n != -1)
        solve(n);
    return 0;
}