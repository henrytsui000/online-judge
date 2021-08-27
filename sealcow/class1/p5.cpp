#include <bits/stdc++.h>
using namespace std;

string ans;
int l, r;

void dfs(int n) {
    if (l < r) return;
    if (ans.size() == n * 2) {
        if (l == r) {
            cout << ans << '\n';
        }
        return;
    }
    ans += '(', l++;
    dfs(n);
    ans.pop_back(), l--;
    ans += ')', r++;
    dfs(n);
    ans.pop_back(), r--;
}

int main() {
    int n;
    while (cin >> n) {
        dfs(n);
    }
}