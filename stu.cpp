#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define endl '\n'
#define all(a) a.begin(), a.end()
#define sz(a) ((int)a.size())
<<<<<<< HEAD
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define eb emplace_back
const int maxn = 1e5 + 5;

int32_t main() {
=======

#define rep(i, n) for (int i = 0; i < (int)n; i++)

#define eb emplace_back
const int maxn = 1e5 + 5;

int32_t main() {
    const int n = 10;
    int arr[n];

    arr[4] = 13;

    for (int xx = 0; xx < (int)n; xx++) {
        arr[xx] = xx + 1;
    }
    random_shuffle(arr, arr + n);
    rep(i,n) {
        cout << arr[i] << ' ';
        rep(j, 3) {
            cout << "wAHAHA" << endl;
        }
    }
    cout << endl;
>>>>>>> cf99d46d907dd3551fe87a56ebcfc48f36362f5f
    return 0;
}