#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'



using ll = long long;

const int maxn = 1e5+5;

struct node {
    node *rc, lc;
    int l, r;
    int val;
    void push() { val = min(rc->val, lc->val); }
};

int arr[maxn];

node* root;

node* build(int l, int r) {
    if (l == r - 1) {
        return new node { 0, 0, l, r, arr[l]; }
    }
    int mid = (l + r) >> 1;
    node* ret;
    ret->lc = build(l, mid);
    ret->rc = build(mid, r);
    ret->push();
    return ret;
}

void chg(int x, int val, node* nd) {
    int mid = (nd->lc + nd->rc) >> 1;
    if (x < mid)
        chg(x, val, nd->lc);
    else
        chg(x, val, nd->rc);
    nd->push();
}
int qry(int l, int r, node* nd) {
    if (l == r - 1) {
        return nd->val;
    }
    int mid = (nd->l + nd->r) >> 1;
    if (l > mid)
        return qry(mid, r, nd->rc);
    else if (r < mid)
        return qry(l, mid, nd->lc);
    else {
        return min(qry(l, mid, nd->lc), qry(mid, r, nd->rc));
    }
}

int32_t main(){
    int n;
    cin>>n;
    rep(i,n)
        cin>>arr[i];
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        qry(a,b,root);
    }
    return 0;
}
