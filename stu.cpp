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

int st[maxn<<2];
#define ir(x) (2*x+1)
#define il(x) (2*x)

void build(int l,int r,int nd){
    if(l==r-1){
        st[nd]=0;
    }else{
        int mid=(l+r)>>1;
        build(l,mid,il(nd));
        build(mid,r,ir(nd));
        st[nd]=max(st[il(nd)],st[ir(nd)]);
    }
}

void add(int nd,int x,int val,int l,int r){
    if(l==r-1){
        st[nd]+=val;
        // cout<<nd<<' '<<val<<endl;
    }else{
        int mid=(l+r)>>1;
        if(x<mid) add(il(nd),x,val,l,mid);
        else add(ir(nd),x,val,mid,r);
        st[nd]=max(st[il(nd)],st[ir(nd)]);
    }
}

void cal(int nd,int l,int r){
    // cout<<l<<' '<<r<<' '<<nd<<endl;
    if(l!=r-1){
        int mid=(l+r)>>1;
        cal(il(nd),l,mid);
        cal(ir(nd),mid,r);
    }
}

void rmq(){
    if(st[1]==1){
        ans++;
    }
}

void solve(){
    build(0,n,1);
    rep(i,m){
        add(1,chg[i],1,0,n);
    }
    rmq();
    for(int i=m;i<n;i++){
        add(1,chg[i],1,0,n);
        add(1,chg[i-m],-1,0,n);
        rmq();
    }
    cout<<ans<<endl;
}

int32_t main(){
    IOS;
    getnum();
    dis();
    cal(1,0,n);
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