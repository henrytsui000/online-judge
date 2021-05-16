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
#define int ll
const int maxn = 1e5 + 5;

string itos(int k) {
    string tmp;
    while (k) {
        tmp += (k % 10 + '0');
        k /= 10;
    }
    string ret;
    for (int i = 0; i < sz(tmp); i++)
        ret += tmp[sz(tmp) - i - 1];
    return ret;
}

bool pal(int n) {
    if(n<10)return true;
    string str = itos(n);
    for(int i =0 ; i < sz(str);i++)
        if(str[i]!=str[sz(str)-i-1])
            return true;
    return false;
}

ll rev(int n) {
    string str="";
    while(n){
        str+=((n%10)+'0');
        n/=10;
    }
    return stoll(str);
}

void solve() {
    int n;
    cin >> n;
        cout << n << ' ';
        n += rev(n);
    while (pal(n)) {
        cout << n << ' ';
        n += rev(n);
        if (n > pow(2,32)) {
            cout << "overflow\n";
            return;
        }
    }
    cout << n << endl;
    return;
}

int32_t main() {
    int n;
    cin >> n;
    rep(i, n) {
        solve();
    }
    return 0;
}