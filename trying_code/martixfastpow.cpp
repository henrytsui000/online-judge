#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct mat {
    int arr[2][2];
};

mat muti(mat a, mat b) {
    mat ret;
    rep(i, 2) rep(j, 2)
        ret.arr[i][j] = 0;
    rep(i, 2) rep(j, 2) rep(k, 2)
        ret.arr[j][i] += a.arr[k][i] * b.arr[j][k];
    return ret;
}

mat ans;
void mypow(mat a, int b) {
    while (b) {
        if (b & 1)
            ans = muti(ans, a);
        a = muti(a, a);
        b >>= 1;
    }
    cout << ans.arr[0][0] << endl;
}

int main() {
    mat a;
    int n;
    ans.arr[0][0] = ans.arr[1][0] = 1;
    a.arr[0][1] = 1, a.arr[1][1] = 0;
    a.arr[0][0] = 1, a.arr[1][0] = 1;
    cin >> n;
    if (n < 33)
        mypow(a, n - 2);
    else
        cout << "overflow\n";
    return 0;
}

int main(){
    
}