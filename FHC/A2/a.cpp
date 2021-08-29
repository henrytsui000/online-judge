#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < (int)n; i++)
#define sz(a) ((int)a.size())

void solve() {
    /* todo */
    int n;
    cin >> n;
    string str[n];
    rep(i,n)
        cin >> str[i];
    int mi = 1e9;
    map<int, int> ans;

    //row
    rep(i,n){
        int cnt = 0, flag = 1;
        rep(j,n){
            if(str[i][j] == 'O'){
                flag = 0;
                continue;
            } else if(str[i][j] == '.')
                cnt++;
        }
        if(flag){
            ans[cnt]++;
            mi = min(cnt, mi);
        }
    }


    rep(i,n){
        int cnt = 0, flag = 1;
        rep(j,n){
            if(str[j][i] == 'O'){
                flag = 0;
                continue;
            } else if(str[j][i] == '.')
                cnt++;
        }
        if(flag){
            ans[cnt]++;
            mi = min(cnt, mi);
        }
    }

    if(mi == 1){
        int rel_cnt = 0;
        rep(i,n){
            rep(j,n){
                if(str[i][j] == '.'){
                    int key = 2;
                    rep(ii, n){
                        if(ii!=i&&str[ii][j] != 'X'){
                            key--;
                            break;
                        }
                    }
                    rep(ii, n){
                        if(ii!=j&&str[i][ii] != 'X'){
                            key--;
                            break;
                        }
                    }
                    if(key > 0)
                        rel_cnt++;
                }
            }
        }
        cout << 1 << ' '<< rel_cnt << "\n";
        return;
    }

    if(mi == 1e9)
        cout <<"Impossible\n";
    else 
        cout << mi << ' ' << ans[mi] << "\n";
}

int main() {
    freopen("xs_and_os_input.txt", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int T;
    cin >> T;
    
    for (int test = 1; test <= T; ++test) {
        cout << "Case #" << test << ": ";
        solve();
    }
    
    return 0;
}