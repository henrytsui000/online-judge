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
#define rep1(i, n) for (int i = 1; i <= (int)n; i++)
#define pb push_back
#define eb emplace_back
#define mp(a, b) make_pair(a, b)
#define cans cout << ans << endl
#define in cout << "in lar" << endl
#define SORT_UNIQUE(c)         \
    (sort(c.begin(), c.end()), \
     c.resize(distance(c.begin(), unique(c.begin(), c.end()))))
#define GET_POS(c, x) (lower_bound(c.begin(), c.end(), x) - c.begin())
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

const int maxn = 1e5 + 5;
int arr[maxn];
struct node {
    node *lc, *rc;
    int l, r;
    int val;
    void pull() { val = max(rc->val, lc->val); }
};

node* root;
node* build(int l, int r) {
    if (l == r - 1) {
        return new node{0, 0, l, r, arr[l]};
    } else {
        int mid = (l + r) >> 1;
        node* ret = new node{build(l, mid), build(mid, r), l, r, 0};
        ret->pull();
        return ret;
    }
}

int qry(int l, int r, node* nd) {
    cout << l << ' ' << r << endl;
    if (l == nd->l && r == nd->r) {
        return nd->val;
    } else {
        int mid = (nd->l + nd->r) >> 1;
        if (l >= mid) {
            return qry(l, r, nd->rc);
        } else if (r <= mid) {
            return qry(l, r, nd->lc);
        } else {
            return max(qry(l, mid, nd->lc), qry(mid, r, nd->rc));
        }
    }
}

void gogo(node* nd) {
    if (nd->rc == 0) {
        cout << nd->l << ' ' << nd->r << ' ' << nd->val << endl;
    } else {
        gogo(nd->lc);
        gogo(nd->rc);
        cout << nd->l << ' ' << nd->r << ' ' << nd->val << endl;
    }
}

int32_t main() {
    int n;
    cin >> n;
    rep(i, n) cin >> arr[i];
    root = build(0, n);
    gogo(root);
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << qry(a, b + 1, root) << endl;
    }
    return 0;
}