#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
using ll = long long;
#define int ll
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define endl '\n'
#define all(a) a.begin(), a.end()
#define sz(a) ((int)a.size())
#define mem(a, b) memset(a, (b), sizeof(a))
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define eb emplace_back
const ll maxn = 2000005;

ll arr[maxn];
ll s[maxn];
ll c[maxn];

inline long redi() {
    unsigned long ret = 0;
    char ch = getchar_unlocked();
 
    while (!isdigit (ch) && ch!=EOF) {
        ch = getchar_unlocked();
    }
    if(ch==EOF)
        return -1;
    while (isdigit (ch)) {
        ret = ret*10  + ch - 48;
        ch = getchar_unlocked();
    }
    return ret;
}
inline void print(	unsigned long x) {
    unsigned long y=10,len=1;
    while(y<=x)    {y*=10;len++;}
    while(len--){y/=10;putchar_unlocked(x/y+48);x%=y;}
}

int32_t main() {
    IOS;
    ll t;
    t=redi();
    while (t--) {
        ll n, k;
        n=redi();
        k=redi();
        rep(i, n) arr[i]=redi();
        rep(i, n) c[i]=redi();
        s[n] = 0;
        for (ll i = n - 1; i >= 0; i--) s[i] = s[i + 1]+c[i];
        ll ans = 0, itr = 0;
        rep(i, n) {
            while ((arr[itr] <= arr[i] + k) && (itr < n)) itr++;
            if (itr >= n) break;
            ans += (s[itr] * c[i]);
        }
        print(ans);
        putchar_unlocked('\n');
    }
    return 0;
}