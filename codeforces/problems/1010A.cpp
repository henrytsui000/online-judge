#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define endl '\n'
#define all(a) a.begin(), a.end()
#define sz(a) ((int)a.size())
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define eb emplace_back
const int maxn = 1e3 + 5;
int arr[maxn];
int brr[maxn];
int n;
vector<int> vec;
bool cal(ld x, ld st) {
    for (int i : vec) {
        x -= (x / i);
        if (x < st) return 0;
    }
    return 1;
}
// #define ld ll
void solve() {
    cin >> n;
    ld st;
    cin >> st;
    bool key = false;
    rep(i, n) cin >> arr[i];
    rep(i, n) cin >> brr[i];
    rep(i, n - 1) vec.eb(arr[i]), vec.eb(brr[i + 1]);
    vec.eb(arr[n - 1]), vec.eb(brr[0]);
    for (int x : vec) {
        if (x == 1) {
            cout << -1 << endl;
            return;
        }
    }
    ld l = 0, r = 1e9;
    // rep(i,100){
    //     cout<<i<<": "<<cal(st+i,st)<<endl;
    // }
    while (l + 3e-8 < r) {
        ld mid = (l + r) / 2;
        // cout<<l<<' '<<r<<' ';
        // cout <<"mid: "<< mid << endl;
        if (cal(st + mid, st))
            r = mid;
        else
            l = mid;
    }
    cout<<setprecision(7)<<l<<endl;
}

int32_t main() {
    solve();
    return 0;
}