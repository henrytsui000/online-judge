#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int arr[maxn];

bool cmp(int a, int b) {
    if (a % 10 != b % 10)
        return a % 10 < b % 10;
    else
        return a > b;
}

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr + n, cmp);
        for (int i = 0; i < n; i++)
            cout << arr[i] << ' ';
        cout << endl;
    }
    return 0;
}
