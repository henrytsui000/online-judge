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

/******good luck******/
#define int ll
const int maxn = 1e5 + 5;
int arr[maxn];

int cal(int r, int n) {
    int cnt = 0, cntt = 0;
    rep(i, n) {
        if (log(r) / log(10) * (n - 1) >= 18) return INF64;
        cnt += abs(arr[i] - pow(r, i));
        cntt += arr[i] - 1;
    }
    cout << cntt << endl;
    return cntt;
}

void solve() {
    mem(arr, 0);
    int n, ans = 1e18;
    cin >> n;
    rep(i, n) cin >> arr[i];
    sort(arr, arr + n);
    int mx = pow(1e17, 1.0 / n);
    for (int i = 1; i <= mx; i++) {
        int cnt = 0;
        rep(j, n) { cnt += abs(arr[j] - pow(i, j)); }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}

int32_t main() {
    IOS;
    // tryi/ng();
    // cout<<log(1000)/log(10)<<endl;
    solve();
    return 0;
}
/*
100
2822 374 4 5146 3893720 19 162293587 767 128 2906 473697099 790471844 12 123
209702 9514 2 15142567 12 16286175 10 7626 103831758 8 1130 2 1 3 134831
20174393 24 240511765 368093800 35986499 679271 181 157 161014 334283297 10556 3
55 12 7055812 22 9 2 82649122 42830504 6743558 317842 1 69382656 51127531 2
23391036 583 158075560 898311564 507376642 373734413 32413364 159 72 45101931
2081433 4 1433 90153843 2691952 385 24976 2 2339 22767706 4499374 1184 3616105
316304701 488527701 263000 394 2309 16026 ...
*/