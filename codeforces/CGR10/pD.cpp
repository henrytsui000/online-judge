#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define endl '\n'
#define all(a) a.begin(), a.end()
#define sz(a) ((int)a.size())
#define F first
#define S second
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep1(i, n) for (int i = 1; i < (int)n; i++)
#define pb push_back
#define eb emplace_back
#define mp(a, b) make_pair(a, b)
#define cans cout << ans << endl
#define in cout << "in lar" << endl
#define sort_uni(c)            \
    (sort(c.begin(), c.end()), \
     c.resize(distance(c.begin(), unique(c.begin(), c.end()))))
#define get(c, x) (lower_bound(c.begin(), c.end(), x) - c.begin())
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> P) {
    out << '(' << P.F << ',' << P.S << ')';
    return out;
}

//}}}
const ll INF64 = 8000000000000000000LL;
const int INF = 0x3f3f3f3f;
const ll MOD = ll(1e9 + 7);
const ld PI = acos(-1);
const ld eps = 1e-9;
// const ll p=880301;
// const ll P=31;

ll mypow(ll a, ll b) {
    ll res = 1LL;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

/******good luck******/
#define int ll
int cal(int a, int b) {
    int c = a, d = b;
    if (a % 3 == 1)
        b -= 2;
    else if (a % 3 == 2)
        b -= 1;
    if (d % 3 == 1)
        c -= 2;
    else if (d % 3 == 2)
        c -= 1;
    return min((a / 3) + (b + 1) / 3, d / 3 + (c + 1) / 3);
}

void solve() {
    IOS;
    int n;
    cin >> n;
    ll ans = 0;
    string str;
    cin >> str;
    bool k1 = true;
    rep(i, n) if (str[0] != str[i]) k1 = false;

    if (k1) {
        cout << n / 2 << endl;
        return;
    } else {
        int cnt = 0;
        // have l have r
        while (str[cnt] == 'R') cnt++;
        while (str[cnt] == 'L') cnt++;

        int clt = 0, crt = 0, cct = 0;
        for (int i = cnt; cct < n; i++, i %= n, cct++) {
            if (str[i] == 'L' && str[(i + 1) % n] == 'R')
                ans += cal(crt, clt + 1), clt = 0, crt = 0;
            else if (str[i] == 'R')
                crt++;
            else
                clt++;
        }
        cout << ans << endl;
        return;
    }
}

int32_t main() {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
