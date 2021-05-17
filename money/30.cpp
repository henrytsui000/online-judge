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

void hanoi(int n, int a, int b, int c) {
    if (!n) return;
    hanoi(n - 1, a, c, b);
    cout << char('A' + a) << "->" << char('A' + c) << endl;
    hanoi(n - 1, b, a, c);
}

void gogo(int n) {
    cout << (1 << n) - 1 << endl;
    hanoi(n, 0, 2, 1);
}

void solve(){
    int n;
    cin >> n;
    gogo(n);
}

int32_t main(){
    int n;
    cin >> n;
    rep(i,n){
        solve();
    }
    return 0;
}