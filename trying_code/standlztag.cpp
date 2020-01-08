#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define eb emplace_back
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define gp(c,x) (lower_bound(c.begin(),c.end())-c.begin())

struct Node{
    Node *lc,*rc;
    int l,r;
    int data;
    bool lt;
    int lv;
};

const int maxn = 1e5+5;
int arr[maxn];

Node *build(int l,int r){
    Node *ret;
    
}

int qry(int l,int r,Node *nd){
    if(nd->l==l&&nd->r==r){
        return nd->data;
    }
    int mid=(nd->l+nd->r)>>1;
    if(nd->lt){
        nd->lc->lt=1;
        
    }
    if(mid>l){
        return qry(l,r,nd->rc);
    }else if(mid<r){
        return qry(l,r,nd->lc);
    }else{
        return (qry(l,r,nd->lc)+qry(l,r,nd->rc));
    }
}

int32_t main(){

    return 0;
}