#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<ld,ld>;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define F first
#define S second
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define pb push_back
#define eb emplace_back
#define mp(a,b) make_pair(a,b)
#define cans cout<<ans<<endl
#define in cout<<"in lar"<<endl
#define sort_uni(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define get(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
    out<<'('<<P.F<<','<<P.S<<')';
    return out;
}
#define int long long
//}}}
const ll INF64=8000000000000000000LL;
const int INF=0x3f3f3f3f;
const ll MOD=1013;
const ld PI=acos(-1);
const ld eps=1e-9;
//const ll p=880301;
//const ll P=31;

ll mypow(ll a,ll b){
    ll res=1LL;
    while(b){
        if(b&1) res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

/******good luck******/

/*
int code = 0;
for (int i = 0; i < spell_name.size(); i++)
    code = (code * 31 + spell_name[i]) % MOD;
*/

void solve() {
    int goal, sz, code = 0;
    string s;
    cin >> goal >> s, sz = s.size();

    for (int i = 0; i < sz; ++i) {
        code = (code * 31 + (s[i] == '?' ? 0 : s[i])) % MOD;
    }

    // cerr << code << "\n";

    int dp[12][MOD + 5];
    pair<int, char> lst[12][MOD + 5]; /// (pl, ch)
    int val[sz + 5], cnt = 0;
    memset(dp, 0x00, sizeof(dp));
    dp[0][code] = 1, val[sz - 1] = 1;
    for (int i = sz-2; i >= 0; --i) val[i] = val[i + 1] * 31 % MOD;

    // for (int i = 0; i < sz; ++i) cerr << val[i] << " \n"[i == sz-1];

    for (int i = 0; i < sz; ++i) {
        if (s[i] == '?') {
            ++cnt;
            for (char c = 'a'; c <= 'z'; ++c) {
                for (int j = 0; j < MOD; ++j) {
                    dp[cnt][(j + c * val[i]) % MOD] += dp[cnt - 1][j];
                    if (dp[cnt - 1][j]) lst[cnt][(j + c * val[i]) % MOD] = mp(j, c);
                }
            }
        }
    }

    if (dp[cnt][goal] != 1) cout << dp[cnt][goal] << "\n";
    else {
        int now = goal;
        stack<char> stk;
        for (int i = cnt; i >= 1; --i) {
            stk.push(lst[i][now].S);
            now = lst[i][now].F;
        }

        for (auto c : s) {
            if (c == '?') cout << stk.top(), stk.pop();
            else cout << c;
        }
        cout << "\n";
    }
}

int32_t main(){
    IOS;

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) cout << "Case #" << tc << ": ", solve();

    return 0;
}
