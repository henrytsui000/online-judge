#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
int p(int n){

    return n*n;
}

int32_t main(){
    IOS;
    int a[3];
    rep(i,3)
        cin>>a[i];
    sort(a,a+3);
    if(p(a[0])+p(a[1])==p(a[2]))
        cout<<"right triangle"<<endl;
    else if(p(a[0])+p(a[1])<p(a[2]))
        cout<<"obtuse triangle"<<endl;
    else cout<<"acute triangle"<<endl;
    return 0;
}
