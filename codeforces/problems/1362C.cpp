#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'

ll count(ll a){
    int ret=0;
    while(a){
        if(a&1)
            ret++;
        a>>=1;
    }
    return ret;
}

int32_t main(){
    int t; cin>>t;
    while(t--){
        ll a;cin>>a;
        cout<<2*a-count(a)<<endl;
    }
    return 0;
}