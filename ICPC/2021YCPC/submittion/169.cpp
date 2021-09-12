#pragma GCC optimize("Ofast", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
using pii = pair<int, int>;
template<typename T>
using Prior = std::priority_queue<T>;
template<typename T>
using prior = std::priority_queue<T, vector<T>, greater<T> >;

#define X first
#define Y second
#define eb emplace_back
#define ALL(x) begin(x), end(x)
#define RALL(x) rbegin(x), rend(x)
#define fastIO() ios_base::sync_with_stdio(0), cin.tie(0)
#define endl '\n'


template<typename T>
bool chmin(T &lhs, T rhs) {return lhs < rhs ? true : (lhs = rhs, false);}

template<typename T>
bool chmax(T &lhs, T rhs) {return lhs > rhs ? true : (lhs = rhs, false);}

void solve() {
    /* do something */
    int a, b;
    char c;
    cin >> a >> c >> b;
    if( a < 24 ) {
        cout << "NO" << endl;
        return;
    }
    
    if ( a == 24 ){
        cout << ( b <= 28 ? "YES": "NO" ) << endl;
        return;
    }
    
    int P = a/4;
    int esc = a-4*P;
    int bb = 6*P-8+esc;
    //cout << "bb:" << bb << endl;
    //cout <<"DEB:" << N << endl;
    //cout << N*6+4 << endl;
    if( b <= bb){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
    
}

int32_t main() {
    fastIO();
    
    int t = 1;
    cin >> t;
    for (int _ = 1; _ <= t; ++_) {
        solve();
    }
    
    return 0;
}