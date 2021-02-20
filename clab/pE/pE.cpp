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

int32_t main(){
    int n, m, ans = 1, tmp = 1;
    cin >> n >> m;
    rep(i,n) ans *= (i+1);
    rep(i,m) ans /= (i+1);
    cout<<ans+pow(n,m)<<endl;
    return 0;
}