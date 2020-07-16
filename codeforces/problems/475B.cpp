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
    int n,m;cin>>n>>m;
    string sn,sm;
    cin>>sn>>sm;
    bool key=true;
    if(sn[0]==sn[n-1]||sm[0]==sm[m-1])
        key=0;
    if(sn[0]=='<'&&sm[0]=='^')
        key=0;
    if(sn[0]=='>'&&sm[0]=='v')
        key=0;
    if(!key)
        cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}