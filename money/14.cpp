#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define endl '\n'
#define all(a) a.begin(), a.end()
#define sz(a) ((int)a.size())
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define eb emplace_back
multiset<int> ans;


void gogo(int n) {
    int itr = 2;
    for (; n != 1; itr++) {
        while (n % itr == 0) {
            ans.insert(itr);
            n /= itr;
        }
    }
}

void solve(int n) {
    
    for(int i = 2 ; i <= n ; i++){
        gogo(i);
    }
    cout << n << "! = (";
    rep(i,n){
        if(ans.count(i))
            cout << ans.count(i) <<' ';
    }
    cout << ")\n";
    ans.clear();
}

int32_t main() {
    string n;
    while (cin >> n && n != ".") {
        solve(stoi(n));
    }
    return 0;
}