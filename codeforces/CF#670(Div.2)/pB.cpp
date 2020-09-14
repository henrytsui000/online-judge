#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
using ll = long long;
#define int ll
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define endl '\n'
#define mem(a, b) memset(a, (b), sizeof(a))
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
#define int ll
/******good luck******/
const int maxn = 1e5 + 5;
int arr[maxn];
void solve() {
    int n;
    cin >> n;
    vector<int> ans;
    rep(i, n) cin >> arr[i];
    sort(arr, arr + n);
    rep(i, 5) ans.eb(arr[i]);
    for (int i = max(n - 5, 0ll); i < n; i++) {
        // cout<<i<<endl;
        ans.eb(arr[i]);
    }

    // for (auto x : ans) cout << x << ' ';
    // cout << endl;
    int aa = ans[0] * ans[1] * ans[2] * ans[3] * ans[4];
    rep(i, 5) {
        int tmp = 1;
        // for (int j = 0; j < i; j++) cout<<j<<' ';
        for (int j = 0; j < i; j++) tmp *= ans[j];
        // cout<<tmp<<' ';
        // for (int j = 0; j < 5 - i; j++) cout<<n-j-1<<' ';
        // cout<<endl;
        for (int j = 0; j < 5 - i; j++) tmp *= ans[sz(ans) - j - 1];
        // cout << i << ' ' << 5 - i << ' ';
        // cout << tmp << endl;
        aa = max(aa, tmp);
    }
    // cout << endl;
    cout << aa << endl;
}

int32_t main() {
    IOS;
    int t;
    cin >> t;
    rep(i, t) {
        // cout << "Case " << i + 1 << ": ";
        solve();
    }
    return 0;
}
