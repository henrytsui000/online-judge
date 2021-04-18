#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int maxn = 1e5+5;
#define int ll
int32_t main(){
    vector<int> vec;
    for(int i = 1; i < 20; i++)
        vec.eb(i);
    int a;
    int ans = 0;
    cin >> a;
    if(a <= 2)
        cout << a << endl;
    else {
        rep(i,10){
            rep(j,10){
                rep(k,10){
                    int tmp;
                    if(i != j && j!=k && i!=k && a > max({i,j,k})){
                        tmp = (a-i)*(a-j)*(a-k);
                        tmp/=__gcd(a-i,a-j);
                        tmp/=__gcd(a-j,a-k);
                        tmp/=__gcd(a-i,a-k);
                        ans = max(ans, tmp);
                    }
                }
            }
        }

        cout<< ans << endl;
    }
    return 0;
}