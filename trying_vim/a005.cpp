#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
int main(){
    IOS;
    int t;
    cin>>t;
    while(t--){
        int arr[4];
        int m=1,a=0;
        rep(i,4){
            cin>>arr[i];
            m*=arr[i];
            a+=arr[i];
        }
        rep(i,4)    
            cout<<arr[i]<<' ';
        if(arr[1]*arr[2]*arr[1]*arr[2]==m){
            cout<<arr[3]*arr[3]/arr[2]<<endl;
        }else cout<<arr[3]+arr[3]-arr[2]<<endl;
    }
    return 0;
}
