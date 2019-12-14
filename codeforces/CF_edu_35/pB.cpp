#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
int32_t main(){
    IOS;
    int n,a,b;
    cin>>n>>a>>b;
    int p1=(n*a)/(a+b);
    cout<<max(min(a/p1,b/(n-p1)),min(a/(p1+1),b/(n-p1-1)))<<endl;
    return 0;
}