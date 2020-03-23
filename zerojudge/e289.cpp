#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int maxn = 2*1e5+5;
int ans;

string arr[maxn];
int chg[maxn];
vector<string> vec;
int n,m;

void getnum(){
    cin>>m>>n;
    int mx=0;
    rep(i,n){
        cin>>arr[i];
        mx=max(sz(arr[i]),mx);
    }
    rep(i,n){
        string s="";
        rep(j,mx-sz(arr[i]))
            s=s+'0';
        arr[i]=s+arr[i];
        vec.eb(arr[i]);
    }
}

void dis(){
    sort(all(vec));
    vec.resize(unique(all(vec))-vec.begin());
    rep(i,n){
        chg[i]=lower_bound(all(vec),arr[i])-vec.begin();
    }
}

struct Node{
    Node *lc,*rc;
    int l,r;
    int val;
    void pull(){
        val=max(lc->val,rc->val);
    }
};

Node *root;

Node* build(int l,int r){
    if(l==r-1) return new Node{nullptr,nullptr,l,r,0};
    int mid=(l+r)>>1;
    Node *ret=new Node{build(l,mid),build(mid,r),l,r,0};
    ret->pull();
    return ret;
}

void add(Node *nd,int x,int val){
    if(nd->l==x&&nd->r==x+1)
        nd->val+=val;
    else{
        int mid=(nd->l+nd->r)>>1;
        if(x<mid) add(nd->lc,x,val);
        else add(nd->rc,x,val);
        nd->pull();
    }
}

void rmq(){
    if(root->val==1){
        ans++;
    }
}


void cal(Node *nd){
    cout<<nd->l<<' '<<nd->r<<endl;
    if(nd->lc!=nullptr)
        cal(nd->lc);
    if(nd->rc!=nullptr)
        cal(nd->rc);
}

void solve(){
    root=build(0,n);
    rep(i,m){
        add(root,chg[i],1);
    }
    rmq();
    for(int i=m;i<n;i++){
        add(root,chg[i],1);
        add(root,chg[i-m],-1);
        rmq();
    }
    cout<<ans<<endl;
}

int32_t main(){
    IOS;
    getnum();
    dis();
    // cal(root);
    solve();
    return 0;
}

/*
2 3
132851
34984
406484

1 5
13 28 53 66 79
*/