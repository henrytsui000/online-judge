#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'

struct node{
    node *rc,*lc;
    int l,r;
    int data;

    void pull(){
        data=max(lc->data,rc->data);
    }
};

const int maxn = 1005;
int arr[maxn];

node *build(int l,int r){
    if(l==r-1)
        return new node{0,0,l,r,arr[l]};
    int mid=(l+r)>>1;
    node *ret=new node{build(l,mid),build(mid,r),l,r,0};
    ret->pull();
    return ret;
}

int qry(int l,int r,node *nd){
    if(nd->l==l&&nd->r==r)
        return nd->data;
    else{
        int mid=(l+r)>>1;
        if(l>=mid){
            return qry(l,mid,nd->rc);
        }else if(r<=mid){
            return qry(mid,r,nd->lc);
        }else{
            return max(qry(l,mid,nd->rc),qry(mid,r,nd->lc));
        }

    }
}

int main(){
    int n;
    cin>>n;
    rep(i,n)    
        cin>>arr[i];
    node *root=build(0,n);
    int q;
    cin>>q;
    rep(i,q){
        int l,r;
        cin>>l>>r;
        if(l>r)
            swap(l,r);
        l--;
        cout<<qry(l,r,root)<<endl;


    }



}