#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'

    #define int long long
int32_t main(){
    IOS;
    int n;cin>>n;
    int cnt=0;
    rep(i,n){
        int a;
        cin>>a;
        cnt+=a;
        cout<<cnt<<' ';
    }
    cout<<endl;
}