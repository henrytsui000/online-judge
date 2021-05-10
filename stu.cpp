#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n;
    vector<pair<int,int> > vec(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        vec[i] = make_pair(a, b);
    }
    sort(vec.begin(), vec.end());
    long long total = 0, curr = 0;
    for (auto x : vec) {
        curr += x.first;
        total += x.second - curr;
    }
    cout << total;
    return 0;
}