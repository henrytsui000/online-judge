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

int32_t main(){
    string str;
    int arr[3];
    rep(i,3)
        cin>>arr[i];
    cin>>str;
    sort(arr, arr+3);
    rep(i,3)
        cout<<arr[str[i]-'A']<<' ';
    cout<<endl;
    return 0;
}