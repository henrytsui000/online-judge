#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int arr[maxn];

bool is_right_tangle(int a, int b, int c) {
    if (a * a + b * b == c * c)
        return true;
    return false;
}

void solve() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (is_right_tangle(arr[i], arr[j], arr[k]))
                    ans++;
            }
        }
    }
    cout << (ans / 2) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}