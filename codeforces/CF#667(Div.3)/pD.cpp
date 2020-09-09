#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
using ll = long long;
#define int ll
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define endl '\n'
#define mem(a, b) memset(a, (b), sizeof(a))
#define all(a) a.begin(), a.end()
#define sz(a) ((int)a.size())
#define F first
#define S second
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep1(i, n) for (int i = 1; i < (int)n; i++)
#define pb push_back
#define eb emplace_back
#define mp(a, b) make_pair(a, b)
#define cans cout << ans << endl
#define in cout << "in lar" << endl
#define sort_uni(c)            \
    (sort(c.begin(), c.end()), \
     c.resize(distance(c.begin(), unique(c.begin(), c.end()))))
#define get(c, x) (lower_bound(c.begin(), c.end(), x) - c.begin())
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> P) {
    out << '(' << P.F << ',' << P.S << ')';
    return out;
}

//}}}
const ll INF64 = 8000000000000000000LL;
const int INF = 0x3f3f3f3f;
const ll MOD = ll(1e9 + 7);
const ld PI = acos(-1);
const ld eps = 1e-9;
// const ll p=880301;
// const ll P=31;

ll mypow(ll a, ll b) {
    ll res = 1LL;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

/******good luck******/
const int maxn = 20;
int arr[maxn];
int dp[maxn];
#define int ll

void solve() {
    mem(arr,0);
    mem(dp,0);
    string str;
    int a;
    cin>>str>>a;
    for(int i = sz(str);i<20;i++)
        str='0'+str;
    int sum=0;
    rep(i,20)
        sum+=(str[i]-'0');
    // cout<<sum<<endl;
    int ans = 0;
    int kk=1;
    for(int i=19;i>=0;i--,kk*=10){
        // cout<<str<<endl;
        if(sum<=a){
            cout<<ans<<endl;
            return;
        }
        if(str[i]=='0')
            continue;
        int tmp = i;
        sum -=(str[i]-'0');
        ans +=((('9'-str[i])+1)*kk);
        // cout<<"Ans:"<<ans<<endl;
        str[i]='0';
        while(str[tmp-1]=='9'){
            tmp--;
            sum-=9;
            str[tmp]='0';
        }
        str[tmp-1]=(str[tmp-1]+1);
        sum++;
    }
}

int32_t main() {
    IOS;
    int t;
    cin >> t;
    rep(i, t) {
        // cout << "Case " << i + 1 << ": ";
        solve();
    }
    return 0;
}
