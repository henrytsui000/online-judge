#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
using ll = long long;
int arr[40];

void init(){
    int a=1;
    rep(i,30)
        arr[i]=a,a<<=1;
}

int32_t main(){
    IOS;init();
    int n;
    while(cin>>n)
        rep(i,30)
            if(n==arr[i]){
                cout<<"YES"<<endl;
                break;
            }else if(n<arr[i]){
                cout<<"NO"<<endl;
                break;
            }
    return 0;
}