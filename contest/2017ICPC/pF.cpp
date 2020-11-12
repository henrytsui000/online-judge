#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<(int)n;i++)
#define int ll
using ll = long long;
using pii = pair<int,int>;
#define X first
#define Y second 
#define SZ(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define eb emplace_back
#define pb push_back
using piii = pair< pair<int,int> ,int >;
vector<piii> vec;
bool cmp(pair<pii,int> a,pair<pii,int> b){
    return a.X>b.X;
}

int32_t main(){
    int n;
    cin>>n;
    rep(i,n)
        cin>>vec[i].X.X>>vec[i].X.Y>>vec[i].Y;
    vector<int> tmp;
    for(auto x: vec)
        tmp.eb(x.X.Y);
    sort(all(tmp));
    tmp.resize(tmp.end()-unique(all(tmp)));
    for(auto &x: vec)
        x.X.Y = lower_bound(all(tmp),x.X.Y)-tmp.begin();
    sort(all(vec),cmp);
    for(auto x: vec)
        printf("%d %d %d",x.X.X,x.X.Y,x.Y);
    return 0;
}

