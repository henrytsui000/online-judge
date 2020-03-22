#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define sz(a) ((int)a.size())
int main(){
    string str;
    cin>>str;
    int ans=0;
    rep(i,sz(str)){
        ans*=10;
        ans+=(str[i]-'0');
    }
    cout<<ans<<endl;
    return 0;
}