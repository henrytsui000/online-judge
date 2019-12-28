#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define resp1(i,n) for(int i=1;i<(int)n;i++)
#define IOS ios_vase::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define eb emplace_back
#define pb push_back
#define mp(a,b) mack_pair(a,b)
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
const int maxn=1000+5;
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
    if(l+1==r)
        return new Node{0,0,l,r,arr[l]};
    int mid=(l+r)>>1;
    Node *ret=new Node{build(l,mid),build(mid,r),l,r,0};
    ret->pull();
    return ret;
}

void chg(int x,int val,Node *nd){
    if(nd->l==x&&nd->r==x+1){
        nd->data+=val;
    }else{
        int mid=(nd->l+nd->r)>>1;
        if(mid>=x){
            chg(x,val,nd->lc);
        }else{
            chg(x,val,nd->rc);
        }
        nd->pull();
    }
}

int qry(int l,int r,Node *nd){
    if(nd->l==l&&nd->r==r){
        return nd->data;
    }else{
        int mid=(nd->l+nd->r)>>1;
        if(mid<=l){
            return qry(l, r,nd->rc);
        }else if(mid>=r){
            return qry(l,r,nd->lc);
        }else{
            return max(qry(l,mid,nd->lc),qry(mid,r,nd->rc));
        }
    }
}

int32_t main(){
    int n;
    cin>>n;
    rep(i,n)
        cin>>arr[i];
    Node *root=build(0,n);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<qry(l,r+1,root)<<endl;
    }
    return 0;
}