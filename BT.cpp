#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'

const int maxn = 1000;
int arr[maxn];

struct node{
    node *rc,*lc;
    int l,r;
    int data;

    void pull () {
        data = max(lc->data, rc->data);
    }
};

node *build(int l,int r){
    if(l==r-1)
        return new node{0,0,l,r,arr[l]};
    int mid=(l+r)>>1;
    node *ret = new node{build(l,mid),build(mid,r),l,r,0};
    ret->pull();
    return ret;
}

void add (int x, int val, node *nd) {
    if (nd->l == x && nd->r == x+1) {
        nd->data += val;
    } else {
        int mid = (nd->l + nd->r) >> 1;
        if (x >= mid) {
            add(x, val, nd->rc);
        } else {
            add(x, val, nd->lc);
        }
        nd->pull();
    }
}

int qry (int l, int r, node *nd) {
    if (l == nd->l && r == nd->r) {
        return nd->data;
    } else {
        int mid = (nd->l + nd->r);
        if (l >= mid) {
            return qry(l, r,nd->rc);
        } else if (r <= mid) {
            return qry(l, r,nd->lc);
        } else {
            return max(qry(l,mid,nd->lc),qry(mid,r,nd->rc));
        }
    }
}
