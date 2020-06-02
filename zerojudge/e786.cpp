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
    bool key =true;
    rep(i,sz(str)/2){
        if(str[i]!=str[sz(str)-1-i])
            key = false;
    }
    if(sz(str)%2) key=false;
    if(key){
        cout<<"YES"<<endl;
        rep(i,sz(str)/2)
            cout<<str[i];
        cout<<endl;
    }else cout<<"NO"<<endl;
    return 0;
}