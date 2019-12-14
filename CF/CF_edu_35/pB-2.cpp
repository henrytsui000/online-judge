#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
int32_t main(){
    int n,a,b;
    cin>>n>>a>>b;
    int p1=(n*a)/(a+b);
    if(!p1)
        p1++;
    if(p1==n)
        p1--;
    if(n-p1==1)
        cout<<min(a/p1,b/(n-p1))<<endl;
    else if(n-p1==0)
        cout<<min(a/(p1+1),b/(n-p1-1))<<endl;
    else if((a+b)%n==0)
        cout<<min(a/p1,b/(n-p1))<<endl;
    else cout<<max(min(a/p1,b/(n-p1)),min(a/(p1+1),b/(n-p1-1)))<<endl;
    return 0;
}