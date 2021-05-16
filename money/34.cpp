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
#define int ll
void solve(int n){
    vector<int> vec;
    printf("For n = %d, the first %d elements of the Hamming sequence are\n", n, n);
    rep(i,10) rep(j,10) rep(k,5)
        vec.eb(pow(2,i)*pow(3,j)*pow(5,k));
    sort(all(vec));
    rep(i,n) cout << vec[i] <<",\n"[i==n-1];
}

int32_t main(){
    int n;
    while(cin >> n) solve(n);
    return 0;
}