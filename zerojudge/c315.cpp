#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
int main(){
    int arr[4]={0};
    int n;
    cin>>n;
    rep(i,n){
        int a,b;
        cin>>a>>b;
        arr[a]+=b;
    }
    cout<<arr[1]-arr[3]<<' '<<arr[0]-arr[2]<<endl;
    return 0;
}