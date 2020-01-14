#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
using ll = long long;
pair<ll,ll> p;
int main(){
    rep(i,9){
        int a;cin>>a;
        p.first+=a;
    }
    rep(i,9){
        int a;cin>>a;
        p.second+=a;
    }
    if(p.first>p.second)
        cout<<"First"<<endl;
    else cout<<"Second"<<endl;
    return 0;
}