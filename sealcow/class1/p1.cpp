#include <bits/stdc++.h>
using namespace std;
int get_length(int n) {
    int cnt = 0;
    while (n) {
        n /= 10, cnt++;
    }
    return cnt;
}

int main() {
    int n, m, has_answer = false;
    cin >> n >> m;
    for (int i = n; i <= m; i++) {
        int length = get_length(i), ans = 0, tmp = i;
        for (int j = 0; j < length; j++) {
            ans += pow(tmp % 10, length);
            tmp /= 10;
        }
        if (ans == i) {
            cout << i << ' ';
            has_answer = true;
        }
    }
    if (has_answer)
        cout << '\n';
    else
        cout << "none\n";
    return 0;
}