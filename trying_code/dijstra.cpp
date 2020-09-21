#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define endl '\n'
#define all(a) a.begin(), a.end()
#define sz(a) ((int)a.size())
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define eb emplace_back
#define X first
#define Y second
#define mp make_pair
const int maxn = 1e5 + 5;

template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> P) {
    out << '(' << P.X << ',' << P.Y << ')';
    return out;
}

bool cmp(pii x, pii y) { return x.Y < y.Y; }

int arr[maxn];
int node[maxn];

vector<pii> edge[maxn];
priority_queue<pii,vector<pii>,greater<pii>>pri,t;

int dsu[maxn], siz[maxn];
bool vis[maxn];
int n;

void init() { rep(i, n) dsu[i] = i, siz[i] = 1; }

void dfs(int np) {
    // cout<<np<<' ';
    vis[np] = 1;
    for (pii x : edge[np]){
        // cout<<np<<' '<< x.X<<' '<< x.Y<<endl;
        if (!vis[x.X]) {
            pri.push({node[np] + x.Y, x.X});
        }
    }
    while (!pri.empty()) {
        pii p = pri.top();
        pri.pop();
        if (!vis[p.Y]) {
            node[p.Y] = p.X;
            dfs(p.Y);
            return;
        }
    }
}


void test(){
    rep(i,10)
        t.push({10-i,i});
    while(!t.empty()){
        cout<<(t.top().X)<<' ';
        t.pop();
    }
    cout<<endl;
}

int32_t main() {
    // test();
    ifstream fin("test.txt");
    int n, m;
    fin >> n >> m;
    rep(i, m) {
        int u, v, x;
        fin >> u >> v >> x;
        edge[u].eb(mp(v, x));
    }
    dfs(0);
    rep(i, n) cout << node[i] << " \n"[n - 1 == i];
    return 0;
}