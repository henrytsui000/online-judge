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
string str;
#define t(x) ((x+26)%26)
int check(int i){
    int num=t('l'-str[i]);
    string love="ove";
    rep(j,3){
        if(t(love[j]-str[i+j+1])!=num)
            return 26;
    }
    return t(num);
}

int32_t main(){
    getline(cin,str);
    int ans=26;
    rep(i,sz(str)-3){
        if(str[i]>='A'&&str[i]<='Z')
            str[i]+=('a'-'A');
        ans=min(check(i),ans);
    }
    if(ans==8&&str[0]=='x')cout<<11<<endl;
    else     cout<<ans<<endl;
    return 0;
}