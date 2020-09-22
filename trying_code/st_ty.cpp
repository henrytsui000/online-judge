#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define endl '\n'
using ll = long long;

const int maxn = 1e5 + 5;

struct node {
    node *lc, *rc;
    int l, r, val, lz;
    void pull() { val = lc->val + rc->val; };
    void push() { lc->lz += lz, rc->lz += lz, lz = 0; }
};

int arr[maxn];

node* root = new node{0, 0, 0, 0, 0, 0};

void add(int l, int r, int x, node* nd) {
    // cout<<nd->l<<' '<<nd->r<<endl;
    if (nd->l == l && nd->r == r) {
        nd->val += x, nd->lz = x;
        return;
    }
    if (nd->l + 1 == nd->r) return;
    int mid = (nd->l + nd->r) >> 1;
    if (!nd->lc) {
        nd->lc = new node{0, 0, nd->l, mid, 0, 0};
        nd->rc = new node{0, 0, mid, nd->r, 0, 0};
    }
    // nd->push();
    if (l > mid) {
        add(l, r, x, nd->rc);
    } else if (r < mid) {
        add(l, r, x, nd->lc);
    } else {
        add(l, mid, x, nd->lc);
        add(mid, r, x, nd->rc);
    }
    nd->pull();
}

int qry(int l, int r, node* nd) {
    printf("[%d, %d) -> %d\n", nd->l, nd->r, nd->val);
    if (nd->l == l && nd->r == r) return nd->val;
    int mid = (nd->l + nd->r) >> 1;
    if (l >= mid)
        return qry(l, r, nd->rc);
    else if (r <= mid)
        return qry(l, r, nd->lc);
    else {
        return (qry(l, mid, nd->lc) + qry(mid, r, nd->rc));
    }
}

void dfs(node* nd) {
    cout << nd->l << ' ' << nd->r << ' ' << nd->val << endl;
    if (nd->lc != 0) dfs(nd->lc);
    if (nd->rc != 0) dfs(nd->rc);
}

int32_t main() {
    ifstream fin("st.txt");

    int n;
    fin >> n;
    root->l = 0, root->r = n;
    rep(i, n) {
        fin >> arr[i];
        add(i, i + 1, arr[i], root);
    }
    // cout<<"---CUT---"<<endl;
    dfs(root);
    int q;
    // cin >> q;
    string str;
    while (cin >> str) {
        if (str == "qry") {
            int a, b;
            cin >> a >> b;
            cout << qry(a, b, root) << endl;
        } else if (str == "add") {
            int l, r, x;
            cin >> l >> r >> x;
            add(l, r-1, x, root);
        } else if (str == "dfs") {
            dfs(root);
        }
    }
    return 0;
}

/*
5
3 5 1 2 4
*/
