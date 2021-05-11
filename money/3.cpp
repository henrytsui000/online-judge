#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define sz(a) ((int)a.size())
ifstream fin("3.in");
ofstream fout("3.out");

struct mat {
    int arr[2][2];
    void Zero() { arr[0][0] = arr[0][0] = arr[0][0] = arr[0][0] = 1; }
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
    fout << ans.arr[0][0] << endl;
}

void solve() {
    mat a;
    int n;
    ans.Zero(), a.Zero();
    ans.arr[0][0] = ans.arr[1][0] = 1;
    a.arr[0][1] = 1, a.arr[1][1] = 0;
    a.arr[0][0] = 1, a.arr[1][0] = 1;
    fin >> n;
    if (n < 2)
        fout << 1 << endl;
    else if (n < 33)
        mypow(a, n - 2);
    else
        fout << "overflow\n";
}

int32_t main() {
    rep(i,10) {
        fout <<"case "<<i+1<<":\n";
        solve();
        fout << endl;
    }
    return 0;
}
