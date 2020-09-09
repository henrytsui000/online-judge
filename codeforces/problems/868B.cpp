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

int32_t main() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    a = (a % 12) * 30 + bool(b) + bool(c);
    b = (b % 60) * 6 + bool(c);
    c = (c % 60) * 6;
    d = (d % 12) * 30;
    e = (e % 12) * 30;
    a = (a - e + 360) % 360;
    b = (b - e + 360) % 360;
    c = (c - e + 360) % 360;
    d = (d - e + 360) % 360;
    if (a < d && b < d && c < d)
        cout << "YES" << endl;
    else if (a > d && b > d && c > d)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    // printf("%d %d %d %d %d\n",a,b,c,d,e);

    return 0;
}