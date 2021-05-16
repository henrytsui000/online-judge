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

void solve(){
    string n, a, b, ans ="";
    cin >> n >> a>> b;
    int key = 0;
    rep(i,sz(n)){
        rep(j, sz(a)){
            if(j>=sz(a))
                break;
            if(n[i+j]!=a[j]){
                break;
            }
            if(j == sz(a)-1 && !key){
                cout <<b;
                key = 1;
            }
        }
        if(key==1)
            key = 2, i+=(sz(a)-1);
        else cout << n[i];
    }
    cout << endl;
}


int32_t main(){
    int n;
    cin >> n;
    IOS;
    rep(i,n){
        cout <<"Case "<<i+1<<": ";
        solve();
    }
    return 0;
}