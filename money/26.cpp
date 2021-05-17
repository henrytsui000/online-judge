#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define in cout<<"in lar"<<endl
const int INF=0x3f3f3f3f;

const int maxn = 10;

struct BCD {
    bool digit[4] = {0};
};

pair<BCD, int> add(BCD a, BCD b, bool carry) {
    BCD c;
    bool G[4], P[4], C[5] = {carry};
    for (int i = 0; i < 4; ++i) {
        G[i] = a.digit[i] & b.digit[i];
        P[i] = a.digit[i] ^ b.digit[i];
        c.digit[i] = P[i] ^ C[i];
        C[i + 1] = G[i] | (P[i] & C[i]);
    }
    return pair<BCD, int>(c, C[4]);
}

void solve() {
    char ops;
    int A, B;
    cin >> ops >> A >> B;
    switch (ops) {
        case '+':
            
            break;
        case '-':
            
            break;
        case '*':
            
            break;
    }
}

int32_t main(){
    IOS;
    int n;
    cin >> n;
    rep(i, n) {
        solve();
    }
    return 0;
}