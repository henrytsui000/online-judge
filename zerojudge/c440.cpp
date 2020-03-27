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
#define int long long
int32_t main(){
    IOS;
    string str;
    cin>>str;
    int sum=0;
    rep(i,sz(str)){
        if(str[i]=='Q')
            sum++;
    }
    int cnt=0,ans=0;
    rep(i,sz(str)){
        if(str[i]=='Q'){
            cnt++;
        }else if(str[i]=='A'){
            ans+=cnt*(sum-cnt);
        }
    }
    cout<<ans<<endl;
    return 0;
}