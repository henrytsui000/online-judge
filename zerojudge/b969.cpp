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
    string str,s;
    getline(cin,str);
    // cin.ignore();
    getline(cin,s);
    string ss="";
    rep(i,sz(str)){
        ss+=str[i];
        if(str[i]==' '){
            cout<<s<<", "<<ss<<endl;
            ss="";
        }
    }
    cout<<s<<", "<<ss<<endl;
    return 0;
}