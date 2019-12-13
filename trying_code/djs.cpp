#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'

const int maxn = 1005;
int djs[maxn],sz[maxn],arr[maxn];

void init(){
    rep(i,maxn){
        djs[i]=i;
        sz[i]=1;
    }
}

int fnd(int x){
    return djs[x]==x?x:djs[x]=fnd(djs[x]);
}

void uni(int x,int y){
    x=fnd(x),y=fnd(y);
    if(x==y)
        return ;
    if(sz[x]<sz[y])
        swap(x,y);
    sz[x]+=sz[y];
    djs[y]=x;
}
vector<int> typ;

int main(){
    int n;
    cin>>n;
    init();
    rep(i,n){
        cin>>arr[i];
        uni(i,arr[i]);
    }
    
    rep(i,n)
        cout<<fnd(i)<<' ';
    cout<<endl;
}