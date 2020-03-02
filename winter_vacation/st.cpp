#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
const int maxn =1e5+5;
int arr[maxn];
int n;
struct Node{
    Node *lc,*rc;
    int l,r;
    int val;
    void pull(){
        val=max(lc->val,rc->val);
    }
};
Node root;
Node *build(int l,int r){
    if(l+1==r)
        return new Node{nullptr,nullptr,l,r,arr[l]};
    else{
        int mid=(l+r)>>1;
        Node *ret=new Node{build(l,mid),build(mid,r)};
        ret->pull();
        return ret;
    }
}

int qry(int l,int r,int L,int R,Node* nd){
    if(l==L&&r==R){
        return nd->val;
    }else{
        int mid=(nd->l+nd->r)>>1;
        if(mid<l) return qry(l,r,L,R,nd->rc);
        else if(mid>r) return qry(l,r,L,R,nd->lc);
        else return max(
            qry(l,mid,L,mid,nd->lc),
            qry(mid,r,mid,R,nd->rc));
    }
}

int main(){
    cin>>n;
    rep(i,n){
        cin>>arr[i];
    }
    Node *root=build(0,n);
    return 0;
}
