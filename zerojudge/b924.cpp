#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int maxn = 1e4+5;
int arr[maxn];

int32_t main(){
    IOS;
    int n,m;
    cin>>n>>m;
    rep(i,m){
        int a,b;cin>>a>>b;
        arr[a]++,arr[b]++;
    }
    int key=0;
    rep(i,n)
        if(arr[i]%2)key++;
    if(key<=2)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}