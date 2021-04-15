#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n;i++)
#define F first
#define S second
const int maxn = 1e3+5;
using pii = pair<int, int >;
pii arr[maxn];

int check(pii a, pii b, pii c){
    return ((b.F-a.F) * (c.S-b.S) > (b.S-a.S) * (c.F - b.F));
}

void solve(){
    int n;
    cin >> n;
    rep(i,n+1)
        cin >> arr[i].F >> arr[i].S;
    int ans = 0;
    rep(i,n - 1){
        ans += check(arr[i], arr[i+1], arr[i+2]);
    }
    cout << ans <<endl;
}

int main(){
    solve();
    return 0;
}