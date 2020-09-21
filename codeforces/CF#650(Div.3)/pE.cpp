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
const int maxn = 2 * 1e5 + 5;
int dsu[maxn];
#define F first
#define S second
int siz[maxn];
vector<int> vec[maxn];
set<int> st;
int n;
using pii = pair<int, int>;
map<int, pii> mp;
map<int, int> rev;

struct ans_node {
    int x, y, z;
};
vector<ans_node> ans;
int fnd(int x) { return x == dsu[x] ? x : fnd(dsu[x]); }

void init() {
    rep(i, n + 3) siz[i] = 1;
    rep(i, n + 3) dsu[i] = i;
}

void uni(int x, int y) {
    x = fnd(x), y = fnd(y);
    if (x == y) return;
    if (siz[y] > siz[x]) swap(y, x);
    siz[x] += siz[y];
    dsu[y] = x;
}

void solve() {
    int tmp;
    cin >> n;
    init();
    int rk = 0;
    rep(i, n) {
        int k;
        cin >> k;
        rep(j, k) {
            int a;
            cin >> a;
            if (mp[a].F == 0) {
                rev[rk] = a;
                mp[a].S = rk++;
                mp[a].F = 1;
            }
            vec[mp[a].S].eb(i + 1);
        }
    }

    // rep(x,n) {
    //     cout<<x<<':';
    //     for (int t : vec[x]) {
    //         cout<<t<<' ';
    //     }
    //     cout<<endl;
    // }

    rep(x, rk) {
        // cout<<"X:"<<x<<endl;
        for (int t : vec[x]) {
            // cout<<"IN:"<<x<<' '<<vec[x][0]<<' '<<t<<'
            // '<<fnd(vec[x][0])<<' '<<fnd(t)<<endl;
            if (fnd(vec[x][0]) != fnd(t)) {
                uni(vec[x][0], t);
                ans.eb(ans_node{vec[x][0], t, x});
            }
        }
    }
    // cout<<sz(ans)<<endl;
    if (sz(ans) + 1 != n) {
        cout << "impossible" << endl;
        return;
    }
    for (ans_node x : ans) {
        cout << x.x << ' ' << x.y << ' ' << rev[x.z] << endl;
    }
}

int32_t main() {
    solve();
    return 0;
}