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
    cin>>str;
    int arr[9];
    rep(i,9)
        arr[i]=str[i]-'0';
    sort(arr,arr+9);
    int k=arr[8]*arr[8]+arr[7]*arr[7];
    int k2=(str[6]-'0')*100+(str[7]-'0')*10+(str[8]-'0');
    if(k==k2)
        cout<<"Good Morning!"<<endl;
    else cout<<"SPY!"<<endl;
    return 0;
}