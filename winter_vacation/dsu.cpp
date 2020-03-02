#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
const int maxn = 1e5+5;
int dis[maxn];
int siz[maxn];
void init(int n){
    rep(i,n){
        dis[i]=i;
        siz[i]=1;
    }
}

int fnd(int n){
    return dis[n]==n ? n:dis[n]=fnd(dis[n]);
}

void uni(int x,int y){
    x=fnd(x);
    y=fnd(y);
    if(x==y)
        return ;
    if(siz[x]<siz[y])
        swap(x,y);
    siz[x]+=siz[y];
    dis[y]=dis[x];
}

bool same(int x,int y){
    return fnd(x)==fnd(y);
}