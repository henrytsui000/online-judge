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

vector<pii> sta[26][2];

bool dfs(int deep, int k) {
    // cout<<deep <<k<<endl;
    if (sz(sta[k][deep % 2]) == 0) {
        return (deep % 2) ^ 1;
    }
    bool mapu;
    for (pii& x : sta[k][deep % 2]) {
        if (x.S) {
            x.S--;
            mapu = dfs(deep + 1, x.F);
            if (deep % 2 == mapu) {
                return mapu;
            }
            x.S++;
        }
    }
    return (deep % 2);
}

void solve() {
    // bst = 0;
    rep(i, 26) { rep(j, 2) sta[i][j].clear(); }
    rep(i, 2) {
        int n;
        cin >> n;
        getchar();
        string str;
        rep(j, n) {
            getline(cin, str);
            // cout << str << endl;
            bool key = true;
            for (pii x : sta[str[0] - 'a'][i]) {
                if (x.F == str[sz(str) - 1] - 'a') x.S++, key = false;
            }
            if (key) sta[str[0] - 'a'][i].eb(mp(str[sz(str) - 1] - 'a', 1));
        }
    }

    bool ans = true;
    rep(i, 26) {
        if (sz(sta[i][0])) {
            for (pii& x : sta[i][0]) {
                // cout<<"ret of dfs:"<<dfs(1, x.F)<<endl;;
                x.S = 0;
                ans &= dfs(1, x.F);
                x.S = 1;
            }
        }
    }
    // cout << "THIS IS ANS:";
    cout << (ans ? 2 : 1) << endl;
}

int32_t main() {
    // IOS;
    int t;
    cin >> t;
    rep(i, t) {
        cout << "Game " << i + 1 << ": player";
        solve();
    }
    return 0;
}
/*
4
3
a poetry string
a poetry string starting with a
a poetry string ending with a
3
generated word
a word ending with b
poetry
2
either one or two
random string
3
another test case
one greatest poetry
be the winner
1
ab
1
bc
1
ab
1
cb
*/

/*
1
9
a
a
a
a
a
a
a
a
a
9
a
a
a
a
a
a
a
a
a
*/