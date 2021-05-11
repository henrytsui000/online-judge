#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define int ll
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int maxn = 1e5+5;

map<int, char> mp;
void init(){
    rep(i,36){
        if( i < 10)
            mp[i] = '0' + i;
        else mp[i] = 'A' + i - 10;
    }
    // rep(i,36)
    //     cout << mp[i] <<' ';
    // cout << endl;
}

void solve(int a, int b){
    stack<char> ans;
    while(a){
        ans.push(mp[a%b]);
        a/=b;
    }    
    while(sz(ans)){
        cout << ans.top();
        ans.pop();
    }
    cout << endl;
}

int32_t main(){
    int a,b;
    IOS;
    init();
    while(cin >> a && a !=-1){
        cin >> b;
        solve(a,b);
    }
    return 0;
}