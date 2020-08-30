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

/******good luck******/
#define int ll

const int maxn = 1e4 + 5;
int cnt[maxn];

bool cmp(pii a, pii b) { return a.F > b.F; }

void solve() {
    int m, n, c;
    cin >> m >> n >> c;
    mem(cnt, 0);
    rep(i, m) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    vector<pii> cal;
    rep(i, n + 1) { cal.pb(mp(cnt[i], (i * i) % c)); }
    sort(all(cal), cmp);
    for(pii x: cal)cout<<x<<endl;
    int ans = 0, s = 0;
    for (pii x : cal) {
        s += x.S;
        ans = max(ans, s * x.F);
    }
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int t;
    cin >> t;
    rep(i, t) {
        cout << "Case " << i + 1 << ": ";
        solve();
    }
    return 0;
}
/*
2
10 3 9
1 1 2 2 1 1 2 3 1 2
10 3 9
1 1 2 2 1 1 2 3 1 2
*/