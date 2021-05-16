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
void r(string x){
    rep(i,sz(x))
        cout <<x[sz(x)-i-1];
    cout << ' ';
}

void solve(string str){
    str+=' ';
    vector<string> vec;
    string tmp = "";
    rep(i,sz(str)){
        if(str[i] == ' ')
            vec.eb(tmp), tmp = "";
        else tmp+=str[i];
    }
    bool rev_c, rev;
    if(vec[0] != "recho"){
        cout <<"Command error !!"<<endl;
        return;
    }
    vec.erase(vec.begin());
    rev_c = rev = false;
    for(string x: vec){
        if(x == "-c")
            rev_c = true;
        else if(x == "-a")
            rev = true;
        else if(x[0] == '-'){
            cout <<"Illegal switches on "<<x<<endl;
            return;
        }
    }
    if(rev)
        reverse(all(vec));
    for(string x: vec){
        if(x !="-a" && x!="-c"){
            if(rev_c) r(x);
            else cout << x<<' ';
        }
    }
    cout << endl;
}

int32_t main(){
    IOS;
    string str;
    while(getline(cin ,str) && str!="."){
        solve(str);
    }
    return 0;
}
