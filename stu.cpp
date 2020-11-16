#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define endl '\n'
#define all(a) a.begin(), a.end()
#define sz(a) ((int)a.size())
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define eb emplace_back
const int maxn = 1e5 + 5;
map<string, char> stc;
void init() {
    stc[".-"] = 'A';
    stc["-..."] = 'B';
    stc["-.-."] = 'C';
    stc["-.."] = 'D';
    stc["."] = 'E';
    stc["..-."] = 'F';
    stc["--."] = 'G';
    stc["...."] = 'H';
    stc[".."] = 'I';
    stc[".---"] = 'J';
    stc["-.-"] = 'K';
    stc[".-.."] = 'L';
    stc["--"] = 'M';
    stc["-."] = 'N';
    stc["---"] = 'O';
    stc[".--."] = 'P';
    stc["--.-"] = 'Q';
    stc[".-."] = 'R';
    stc["..."] = 'S';
    stc["-"] = 'T';
    stc["..-"] = 'U';
    stc["...-"] = 'V';
    stc[".--"] = 'W';
    stc["-..-"] = 'X';
    stc["-.--"] = 'Y';
    stc["--.."] = 'Z';
}

int32_t main() {
    init();
    // IOS;
    int t;
    cin >> t;
    while (t--) {
        string str;
        char ch;
        bool key = true;
        while (key && cin >> str) {
            cout << stc[str];
            ch = getchar();
            if (ch == 10) key = 0;
        }
        cout << endl;
    }
    return 0;
}