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

int f(int a[], int n, int x) {
    int l = 0, r = n - 1;
    x--;
    while (l != r) {
        int mid = (l + r) / 2;
        if (a[mid] <= x)
            l = mid + 1;
        else
            r = mid;
    }
    return l - 1;
}

int32_t main() {
    int arr[10] = {0, 2, 3, 5, 7, 10, 13, 15, 19, 20};
    rep(i, 50) {
        cout << i << ' ' << f(arr, 10, i) << endl;
    }
    return 0;
}