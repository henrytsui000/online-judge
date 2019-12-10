#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define rep(i,n) for(int i=0;i<(int)n;i++)
int main(){
    int a,b;
    cin>>a>>b;
    string str,str2;
    rep(i,a){
        cin>>str2;
        str+=str2;
    }
    rep(i,b){
        cin>>a;
        cout<<str[a-1];
    }
    cout<<endl;
    return 0;
}