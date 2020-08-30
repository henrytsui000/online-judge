#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
#define mem(a, b) memset(a, (b), sizeof(a))
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
ostream &operator<<(ostream &out, pair<T1, T2> P) {
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

map<string, int> m;

pair<string, int> sta[22];

void init() {
    m["Heal"] = 0;
    m["HIT!"] = 1;
    m["Atk"] = 2;
    m["Def"] = 3;
}

int now[2][4];  // life heal atk def now-val
int bst[2][4];  // life heal atk def best-val
int perf, app[2];

void gogo(int x, int step) {
    if (step == 12) return;

    // die?
    if (now[x][0] <= 0) {
        perf = min(perf, step);
        return;
    }

    // upd best
    pair<string, int> ths = sta[5 + 10 * x + step / 2];
    if (m[ths.F] == 1) {
        app[x] = 1;
    } else if (m[ths.F]) {
        bst[x][m[ths.F]] = max(bst[x][m[ths.F]], ths.S);
    }

    // upd now
    rep(i, 4) {
        if (i == 0) {
            now[x][0] += bst[x][1];
        } else if (i == 1 && app[x]) {
            now[!x][0] = max(0, now[x][2] - now[!x][3]);
        } else {
            now[x][i] = max(bst[x][i], now[x][i]);
        }
        gogo(!x, step + 1);
    }
}

void intwo() {
    mem(bst, 0), mem(now, 0), mem(app, 0);
    now[0][0] = now[1][0] = 10;
    rep(j, 2) rep(i, 5) {
        if (sta[i + 10 * j].F == "Atk") {
            bst[j][2] = max(sta[i + 10 * j].S, bst[j][2]);
        } else if (sta[i + 10 * j].F == "Def") {
            bst[j][3] = max(sta[i + 10 * j].S, bst[j][2]);
        } else if (sta[i + 10 * j].F == "HIT")
            app[j] = 1;
    }
}

void solve() {
    perf = 55;
    rep(i, 20) {
        cin >> sta[i].F;
        if (m[sta[i].F] != 1) {
            cin >> sta[i].S;
        }
    }
    intwo();
    gogo(0, 1);
    cout << (perf % 2 ? "win " : "lose ") << perf << endl;
}

int32_t main() {
    IOS;
    init();
    int t;
    cin >> t;
    rep(i, t) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}
/*
1
Atk 5
HIT!
HIT!
HIT!
HIT!
HIT!
HIT!
HIT!
HIT!
HIT!
Def 3
Def 2
Def 2
Def 2
Def 2
Def 2
Def 2
Def 2
Def 2
Def 2
*/