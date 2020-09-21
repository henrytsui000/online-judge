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
bool cmp(int a, int b) { return a > b; }
const int maxn = 105;
int ans[maxn];
int arr[maxn];
int casc[50];

void solve() {
    mem(ans, 0);
    mem(casc, 0);
    mem(arr, 0);

    string str;
    cin >> str;
    int n;
    cin >> n;
    int tmp = n;
    vector<pii> vec;
    rep(i, sz(str)) { casc[str[i] - 'a']++; }
    rep(i, 28) {
        if (casc[i] != 0) vec.eb(mp(casc[i], i));
    }
    rep(i, n) { cin >> arr[i]; }
    vector<int> cst;

    while (tmp) {
        // cout<<"tmp:"<<tmp<<endl;
        cst.clear();
        // cout<<"1SFARR:";
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                cst.eb(i);
                arr[i] = -1;
            }
            // cout<<arr[i]<<' ';
        }
        // cout<<endl;
        while (sz(cst) > vec.back().F) {
            tmp -= vec.back().F;
            vec.pop_back();
        }
        // cout<<"CST:";
        // for(int x: cst){
        //     cout<<x<<' ';
        // }
        // cout<<endl;

        for (int x : cst) {
            for (int i = x; i >= 0; i--) {
                if (arr[i] != -1) arr[i] -= (x - i);
            }
            for (int i = x; i < n; i++) {
                if (arr[i] != -1) arr[i] -= (i - x);
            }
            ans[x] = vec.back().S;
        }
        vec.pop_back();
        // cout<<"ARR:";
        // rep(i,n)
        //     cout<<arr[i]<<' ';
        // cout<<endl;
        bool key = true;
        rep(i, n) if (arr[i] != -1) key = false;
        if (key) break;
        tmp -= (sz(cst));
    }
    rep(i, n) { cout << (char)(ans[i] + 'a'); }
    cout << endl;
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