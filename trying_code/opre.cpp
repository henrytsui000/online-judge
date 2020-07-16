#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int maxn = 1e5+5;
using pii = pair<int,int>;
#define F first
#define S second

bool operator >(pii a,pii b){
    return a.F>a.S;
}  

int32_t main(){
    pii p1,p2;
    cin>>p1.F>>p2.F;
    cout<<(p1.F>p2.F)<<endl;
    int a,b;
    cin>>a>>b;
    cout<<(a>b)<<endl;
    return 0;
}