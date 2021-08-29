#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < (int)n; i++)
#define sz(a) ((int)a.size())

void solve() {
    /* todo */
    string str;
    cin >> str;
    set<char> s = {'A', 'E', 'I', 'O', 'U'};
    map<char, int> mp;
    rep(i,sz(str))
        mp[str[i]]++;
    int same = 0;
    rep(i, sz(str))
        if(str[i]!=str[0])
            same = 1;
    int ans = 1e9*same;
    
    rep(i, 26){
        int cnt = 0;
        rep(j, 26){
            if(i != j)
                cnt += (2-(s.count('A'+j)^s.count('A'+i)))*mp['A'+j];
        }
        ans = min(cnt, ans);
    }
    cout << ans << "\n";
}

int main() {
    freopen("consistency_chapter_1_validation_input.txt", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int T;
    cin >> T;
    
    for (int test = 1; test <= T; ++test) {
        cout << "Case #" << test << ": ";
        solve();
    }
    
    return 0;
}