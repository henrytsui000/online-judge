#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < (int)n; i++)
#define sz(a) ((int)a.size())

void solve() {
    int n, m;
    int tn, tm;
    cin >> n >> m >> tn >> tm;
    if(n + m - 1 > min(tn, tm)){
        cout <<"Impossible\n";
        return;
    }
    cout << "Possible" << endl;
    rep(i, n){
        rep(j, m){
            if(i != 0 ){
                cout << 1 << ' ';
            }else if(j != 0 && j != m-1){
                cout << 1 << ' ';
            }else if(j == 0){
                cout << tn - n - m + 2 << ' ';
            }else {
                cout << tm - n -m + 2 ;
            }
        }
        cout << endl;
    }
}

int main() {
    freopen("traffic_control_input.txt", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int T;
    cin >> T;
    
    for (int test = 1; test <= T; ++test) {
        cout << "Case #" << test << ": ";
        solve();
    }
    
    return 0;
}