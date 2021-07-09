
#include <bits/stdc++.h>
using namespace std;
string s; int a, b;
void dfs(int n) {
    if(a < b) return;
    if(s.size() == n * 2) { if(a == b) cout << s << '\n'; }
    else {
        s.push_back('('); a ++; dfs(n); s.pop_back(); a--;
        s.push_back(')'); b ++; dfs(n); s.pop_back(); b--;
    }
}
main() {
    int n; while(cin >> n) dfs(n);
}