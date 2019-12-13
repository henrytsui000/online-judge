#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
using ll = long long;
const int maxn=15;
int arr[maxn];

struct node{
    node *lc,*rc;
    int l,r;
    int mx;
}*root;

node *build(int l,int r){
    if(r==l+1)
        return new node{0,0,l,r,0};
    int mid=(l+r)<<1;
    return new node{build(l,mid),build(mid,r),l,r,0};
}

void add(int v,node *nd){
    if(nd->l+1==nd->r)
        nd->mx=v;
    else{
        add(v,nd->lc);
        add(v,nd->rc);
        nd->mx=max(nd->lc->mx,nd->rc->mx);
    }
}

void cc(node *nd){
    cout<<nd->mx<<' ';
    if(nd->l+1!=nd->r){
        cc(nd->lc);
        cc(nd->rc);
    }
}

int32_t main(){
    ll n,m;
    cin>>n;
    root=build(0,n);
    rep(i,n){
        cin>>arr[i];
        add(i,root);
    }
    cc(root);
    return 0;
}
