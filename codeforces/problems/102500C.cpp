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
const int maxn = 1e3 + 5;
using pii = pair<int, int>;
#define X first
#define Y second
pii pos[maxn];
int x[maxn];
int cnt[maxn];
void solve() {
    int n;
    cin >> n;
    rep(i, n) { cin >> pos[i].X >> pos[i].Y; }
    int p;
    cin >> p;
    set<int> st;
    rep(i, p) {
        cin >> x[i];
        st.insert(x[i]);
    }
    sort(pos, pos + n);
    int now = 0;
    rep(i, p) {
        while (x[i] > pos[now].Y) ++now;
        if (x[i] < pos[now].X) continue;
        cnt[now]++;
        if (now + 1 < n && pos[now + 1].X == x[i]) ++cnt[now + 1];
    }
    vector<int> tmp;
    rep(i, n) {
        if (cnt[i] < 2) tmp.eb(i);
        if (cnt[i] >= 3) {
            cout << "impossible\n";
            return;
        }
    }
    // cout<<"X:";
    // for(int x: tmp)
    //     cout<<cnt[x]<<' ';
    // cout<<endl;
    vector<int> ans;
    for (int i = 0; i < tmp.size() - 1; ++i) {
        if (cnt[tmp[i]] == 0) {
            int itr = 1;
            while (st.count(pos[tmp[i]].X + itr)) itr++;
            ans.push_back(pos[tmp[i]].X + itr);
        } else if (cnt[tmp[i]] == 1) {
            if ((pos[tmp[i]].Y == pos[tmp[i + 1]].X) &&!st.count(pos[tmp[i]].Y)) {
                ans.push_back(pos[tmp[i]].Y);
                ++cnt[tmp[i + 1]];
            } else {
                int itr = 1;
                while (st.count(pos[tmp[i]].Y - itr)) itr++;
                ans.push_back(pos[tmp[i]].Y - itr);
            }
        }
    }

    if (cnt[tmp.back()] == 0) {
        ans.push_back(pos[tmp.back()].Y);
        ans.push_back(pos[tmp.back()].Y - 1);
    } else if (cnt[tmp.back()] == 1){
        int itr = 0;
        while (st.count(pos[tmp.back()].Y - itr)) itr++;
        ans.push_back(pos[tmp.back()].Y - itr);
    }
    cout << ans.size() << endl;
    for (int ANS : ans) cout << ANS << " ";
    cout << endl;
}

int32_t main() {
    solve();
    return 0;
}