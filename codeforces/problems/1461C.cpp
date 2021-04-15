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
int arr[maxn];

void solve(){
    int n, m;
    cin >> n >> m;
    rep(i,n)
        cin >> arr[i];
    long double ans = 1;
    int lt = n - 1;
    for(int i = n - 1; i >=0 && arr[i] == i + 1; i --, lt--);
    // cout << lt << endl;
    rep(i, m){
        int st;
        long double p;
        cin >> st >> p;
        if(st > lt)
            ans *= (1-p);
    }
    cout << (lt == -1 ? 1 : 1 - ans) << endl;
}

int32_t main(){
    IOS;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}