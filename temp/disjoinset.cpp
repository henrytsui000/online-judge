#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)

const int maxn =1e5+5;
int f[maxn];
int sz[maxn];

int fnd(int x){
    return f[x]==x? x:f[x]=fnd(f[x]);
}

void uni(int x,int y){
    x=fnd(x),y=fnd(y);
    if(f[x]==f[y])
        return ;
    if(sz[x]<sz[y])
        swap(x,y);
    sz[x]+=sz[y];
    f[y]=x;
}

void init(int n){
    rep(i,n){
        sz[i]=1;
        f[i]=i;
    }
}

int32_t main(){
    int n;
    cin>>n;
    init(n);
    rep(i,n){
        int a,b;
        cin>>a>>b;
        uni(a,b);
    }
    int q;
    cin>>q;
    while(q--){
        int a,b;
        if(f[fnd(a)]==f[fnd(b)])
            cout<<"same"<<endl;
        else cout<<"false"<<endl;
    }
    return 0;
}
