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

int fac(int a){return a!=0?a*fac(a-1):1;}

void solve(){
    int n;
    cin >> n;
    int arr[n];
    rep(i,n)
        arr[i] = i+1;
    cout << fac(n)<<endl;
    do{
        rep(i,n)
            cout << arr[i] <<' ';
        cout << endl;
    }while(next_permutation(arr, arr+n));
}

int32_t main(){
    int n;
    cin >> n;
    rep(i,n){
        solve();
    }
    return 0;
}