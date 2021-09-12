#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < (int)n; i++)
#define rep1(i,n) for(int i = 1 ; i < (int)n; i++)
#define sz(a) ((int)a.size())

void solve() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    char arr[3] = {'F', 'F', 'F'};
    int ANS = 1<<30;
    rep(ii, 3){
        int ans = 0;
        string strf;
        rep(i,sz(str)) {
            if(str[i]!=arr[ii])
                strf+=str[i];
        }
        rep1(i,sz(strf)){
            if(strf[i]!=strf[i-1])
                ans++;
        }
        ANS = min(ANS, ans);
    }
    cout << ANS<<endl;
}

int main() {
    freopen("weak_typing_chapter_1_validation_input.txt", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int T;
    cin >> T;
    
    for (int test = 1; test <= T; ++test) {
        cout << "Case #" << test << ": ";
        solve();
    }
    
    return 0;
}