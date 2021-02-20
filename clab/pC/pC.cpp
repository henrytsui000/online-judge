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

int32_t main(){
    int n;
    cin>>n;
    if (n >= 90)      cout << 4.3 << endl;
    else if (n >= 85) cout << 4 << endl;
    else if (n >= 80) cout << 3.7 << endl;
    else if (n >= 77) cout << 3.3 << endl;
    else if (n >= 73) cout << 3 << endl;
    else if (n >= 70) cout << 2.7 << endl;
    else if (n >= 67) cout << 2.3 << endl;
    else if (n >= 63) cout << 2 << endl;
    else if (n >= 60) cout << 1.7 << endl;
    else              cout << 0 << endl;
    return 0;
}