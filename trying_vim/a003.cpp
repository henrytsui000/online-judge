#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
int main(){
    int m,d;
    cin>>m>>d;
    int s=(m*2+d)%3;
    if(s==0)cout<<"普通"<<endl;
    else if(s==1) cout<<"吉"<<endl;
    else cout<<"大吉"<<endl;
    return 0;
}
