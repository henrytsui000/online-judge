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
const int maxn = 1e5 + 5;

struct node {
    int num;
    node *nxt;
};

node *build(int n) {
    int tmp;
    cin >> tmp;
    if (n)
        return new node{tmp, build(n - 1)};
    else
        return new node{tmp, 0};
}

node *itr;

void gogo(node *nd) {
    while (nd) {
        cout << nd->num << ' ';
        nd = nd->nxt;
    }
}

int32_t main() {
    int n;
    cin >> n;
    itr = build(n-1);
    gogo(itr);
    cout << endl;
    cout<<sizeof(itr)<<endl;
    node a;
    cout<<sizeof(a.nxt)<<endl;
    return 0;
}