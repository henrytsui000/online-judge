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

int cal(int n){
    int cnt = 0;
    while(n){
        cnt+=(n%10);
        n/=10;
    }
    return cnt;
}

void solve(){
    int s, n;
    cin >> s >> n;
    int l = 0, r = s + 1;
    while(l != r - 1){
        int mid = (l+r)/2;
        // cout << l << ' ' << r << ' ' << mid << endl;
        if(mid - cal(mid) < n) l = mid;
        else r = mid;
    }
    while(l - cal(l) >= n) l--;
    cout << s - l << endl;
}

int32_t main(){
    solve();
    return 0;
}