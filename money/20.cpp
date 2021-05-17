#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define in cout<<"in lar"<<endl
const int INF=0x3f3f3f3f;

const int maxn = 10;

string hex2bin(char c) {
    switch (c) {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'a': return "1010";
        case 'b': return "1011";
        case 'c': return "1100";
        case 'd': return "1101";
        case 'e': return "1110";
        case 'f': return "1111";
    }
    return "0000";
}

char ans[32][2];

void solve() {
    string t1, x, t2, y, align;
    int b;
    cin >> t1 >> x >> t2 >> y >> b >> align;

    if (t1[0] == 'l') while (x.size() != 8) x = "0" + x;
    else while (x.size() != 4) x = "0" + x;

    if (t2[0] == 'l') while (y.size() != 8) y = "0" + y;
    else while (y.size() != 4) y = "0" + y;

    string c1 = "", c2 = "";
    if (b == 16) c1 = x, c2 = y;
    else {
        for (int i = 0; i < x.size(); ++i) c1 += hex2bin(x[i]);
        for (int i = 0; i < y.size(); ++i) c2 += hex2bin(y[i]);
    }

    int len = max(c1.size(), c2.size());
    for (int i = 0; i < 32; ++i) for (int j = 0; j < 2; ++j) ans[i][j] = ' ';
    if (align[0] == 't') {
        for (int i = 0; i < c1.size(); ++i) ans[i][0] = c1[i];
        for (int i = 0; i < c2.size(); ++i) ans[i][1] = c2[i];
    }
    else {
        for (int i = 0; i < c1.size(); ++i) ans[len - c1.size() + i][0] = c1[i];
        for (int i = 0; i < c2.size(); ++i) ans[len - c2.size() + i][1] = c2[i];
    }

    for (int i = 0; i < len; ++i) cout << ans[i][0] << ans[i][1] << endl;
}

int32_t main(){
    IOS;
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}