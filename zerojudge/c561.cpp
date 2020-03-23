#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define sz(a) ((int)a.size())
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'

int chg(string str){
    int re=0;
    for(int i=sz(str)-1;i>=0;i--){
        re*=10;
        re+=(str[i]-'0');
    }
    return re;
}

int main(){
    int n;
    cin>>n;
    int ans=0;
    rep(i,n){
        string str;
        cin>>str;
        ans=max(ans,chg(str));
    }
    cout<<ans<<endl;
    return 0;
}