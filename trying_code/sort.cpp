#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
struct Edge{
    int u,v;
    int val;
};
vector<Edge> edge;
bool cmp(Edge a,Edge b){
    return a.val>b.val;
}
int main(){
    int n;
    cin>>n;
    rep(i,n){
        Edge a;
        cin>>a.u>>a.v>>a.val;
        edge.push_back(a);
    }
    sort(edge.begin(),edge.end(),cmp);
    rep(i,n)
        cout<<edge[i].u<<' '
        <<edge[i].v<<' '
        <<edge[i].val<<endl;
    return 0;
}