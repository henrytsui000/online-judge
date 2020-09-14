#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define endl '\n'
using ll = long long;
#define int ll
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
const int Mod = 1e9+7;
map<char,int> mp;
#define sz(a) ((int)a.size())

ll mypow(ll a, ll b) {
    ll res = 1LL;
    while (b) {
        if (b & 1) res = res * a % Mod;
        a = a * a % Mod;
        b >>= 1;
    }
    return res;
}

void init(){
    rep(i,10)
        mp['0'+i] = i;
    rep(i,26)
        mp['A'+i] = 10 + i;
    rep(i,26)
        mp['a'+i] = 36 + i;
    mp['-'] = 62;
    mp['_'] = 63; 
}

int cal(int a){
    int ret = 0;
    while(a){
        if(a&1)
            ret++;
        a >>= 1;
    }
    return (6-ret);
}
int32_t main(){
    string str;
    init();
    cin>>str;
    ll ans = 1;
    rep(i,sz(str)){
        ans *= mypow(3,cal(mp[str[i]]));
        ans %= Mod;
    }
    cout<<ans<<endl;
    return 0;
}
