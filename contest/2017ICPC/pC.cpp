#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define int ll
using ll = long long;
using pii = pair<int, int>;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(), a.end()
#define eb emplace_back
#define pb push_back
int32_t main() {
    int n, k;
    cin >> k >> n;
    vector<int> v(k);
    int tmp;
    for (int i = 0; i < n; ++i) cin >> tmp, ++v[tmp - 1];

    auto minE = min_element(ALL(v));
    auto maxE = max_element(ALL(v));
    if (n % k == 0) {
        /// check +x -y
        if (*maxE == n / k + 1 and *minE == n / k - 1) {
            int cntH = 0, cntL = 0;
            for (auto x : v) {
                if (x == n / k + 1) ++cntH;
                if (x == n / k - 1) ++cntL;
            }
            if (cntH == 1 and cntL == 1)
                cout << "-" << (maxE - v.begin()) + 1 << " +"
                     << (minE - v.begin()) + 1 << "\n";
        } else
            cout << "*\n";
    } else if (n % k == 1) {
        /// check -x
        if (*maxE == n / k + 1 and *minE == n / k)
            cout << "-" << (maxE - v.begin()) + 1 << "\n";
        else
            cout << "*\n";

    } else if (n % k == k - 1) {
        /// check +x
        if (*maxE == n / k + 1 and *minE == n / k)
            cout << "+" << (minE - v.begin()) + 1 << "\n";
        else
            cout << "*\n";
    } else {
        cout << "*\n";
    }

    return 0;
}