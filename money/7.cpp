#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define in cout<<"in lar"<<endl
#define eb emplace_back
#define all(x) x.begin(), x.end()
const int INF=0x3f3f3f3f;

const int maxn = 10;

bool solved[maxn];
vector< vector <int> > bt[maxn];

vector< vector <int> > construct(int n) {
    if (solved[n]) return bt[n];
    solved[n] = 1;
    for (int k = n - 1; k >= 0; --k) {
        vector< vector <int> > lt, rt;
        lt = construct(k);
        rt = construct(n - 1 - k);
        for (auto &sol : lt) for (auto &h : sol) ++h;
        for (auto &sol : rt) for (auto &h : sol) ++h;
        for (auto &solL : lt) for (auto &solR : rt) {
            vector<int> tmp; // = solR + vector <int>{0} + solL;
            tmp.reserve(n);
            tmp.insert(tmp.end(), all(solL));
            tmp.eb(0);
            tmp.insert(tmp.end(), all(solR));
            bt[n].eb(tmp);
        }
    }
    return bt[n];
}

void solve(int n) {
    vector< vector <int> > BT = construct(n);
    for (auto &sol : BT) {
        for (auto x : sol) {
            while (x--) cout << ' ';
            cout << "*\n";
        }
    }
}

int32_t main(){
    IOS;
    solved[0] = 1;
    bt[0].eb(vector <int>{});
    int n;
    while (cin >> n) {
        if (n == -1) break;
        solve(n);
        cout << "===\n";
    }
    return 0;
}