#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int maxn = 1e5+5;
const ld pi=acos(-1);
void solve(int n){
    ld R=sqrt(1/(2*(1-cos(2*pi/n))));
    // cout<<R<<endl;

    cout<<2*R*sqrt(2*R*R-1/2)/sqrt(2*R*R-1/2)<<endl;
    cout<<sqrt(2*R*R-1/2)<<endl;
    // ld m=1/(1-cos((2*pi)/n));
    // cout<<m<<endl;
    // cout<<sqrt(m)<<endl;
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int a;cin>>a;
        solve(a*2);
    }
    return 0;
}