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
const int maxn = 1e5 + 5;

int32_t main() {
    int c;
    cin >> c;

    while (c--) {
        int n, k;
        cin >> n >> k;

        set<int> exist;
        vector<int> color(n);

        for (int i = 0; i < n; i++) {
            ll t;
            cin >> t;
            if (exist.count(k - t)) color[i] = true;
            else{

                if (k == t * 2 and exist.count(k - t))
                    exist.erase(t);
                exist.insert(t);
            } 
        }

        for (int i = 0; i < n; i++) cout << color[i] << ' ';
        cout << endl;
    }
}