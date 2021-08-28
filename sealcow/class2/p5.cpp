#include <bits/stdc++.h>
using namespace std;

int ans[5843] = {0, 1};
int p2 = 1, p3 = 1, p5 = 1, p7 = 1;

string str[4] = {"th", "st", "nd", "rd"};

void init() {
    for (int i = 1; i < 5842; i++) {
        while (ans[p2] * 2 <= ans[i]) p2++;
        while (ans[p3] * 3 <= ans[i]) p3++;
        while (ans[p5] * 5 <= ans[i]) p5++;
        while (ans[p7] * 7 <= ans[i]) p7++;
        int min = ans[p2] * 2;
        if (min > ans[p3] * 3) min = ans[p3] * 3;
        if (min > ans[p5] * 5) min = ans[p5] * 5;
        if (min > ans[p7] * 7) min = ans[p7] * 7;

        ans[i + 1] = min;
    }
}

void solve(int n) {
    int ten = n % 10, hundred = n % 100, m = 0;
    if (hundred != 11 && hundred != 12 && hundred != 13)
        m = n % 10;
    cout << "The " << n << str[m < 4 ? m : 0] << " humble number is " << ans[n] << ".\n";
}

int main() {
    init();
    int n;
    while (cin >> n && n) {
        solve(n);
    }
    return 0;
}