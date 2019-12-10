#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define sz(a) ((int)a.size())
#define pb push_back

struct Edge{
    int n,m,w;
    bool operator < (const Edge &edg) const{
        return w>edg.w;
    }
};
vector<Edge> edge;
const int maxn = 1e5+5;
int djs[maxn];
int fnd(int x){
    return x==djs[x]? x:djs[x]=fnd(djs[x]);
}

bool uni(int x,int y){
    x=fnd(x),y=fnd(y);
    if(x==y)
        return false;
    djs[x]=y;
}

void init(){
    rep(i,maxn)
        djs[i]=i;
}

int main(){
    int n,m;
    while(cin>>n>>m){
        rep(i,n)
            cin>>edge[i].n>>edge[i].m>>edge[i].w;
        sort(edge.begin(),edge.end());
        init();
    }
    return 0;
}