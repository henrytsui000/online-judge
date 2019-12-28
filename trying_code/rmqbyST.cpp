#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define eb emplace_back
#define pb push_back
#define all(a) a.begin(),a.end()
#define sz ((int)a.size())
#define sort_uni(c) (sort(c.begin(),c.end()) , c.resize(distance(c.begin(),unique(c.begin,c.end()))))
#define getpos(c,x) (lower_bound(c.begin(),c.end())-c.begin())
#define F first
#define S second

const int maxn =1005;
int arr[maxn];


struct Node{
    Node *lc,*rc;
    int l,r;
    int data;
    void pull(){
        data=max(lc->data,rc->data);
    }
};

Node *build(int l,int r){
    if(l==r-1){
        return new Node{0,0,l,r,arr[l]};
    }
    int mid=(l+r)>>1;
    Node *ret=new Node{build(l,mid),build(mid,r),l,r,0};
    ret->pull();
    return ret;
}

void add(int x,int val,Node *nd){
    
}

int qry(int l,int r,Node *nd){
    if(l == nd->l&& r == nd->r)
        return nd->data;
    int mid=(l+r)>>1;
    if(l>=mid){
        return qry(r,mid,nd->rc);
    }else if(r<=mid){
        return qry(mid,l,nd->lc);
    }else{
        return max(qry(l,mid,nd->lc),qry(mid,r,nd->rc));
    }
}

int32_t main(){
    int n;
    cin>>n;
    rep(i,n){



    }
    int q;
    cin>>q;
    rep(i,q){
        int a,b;
        cin>>a>>b;


    }

    return 0;
}