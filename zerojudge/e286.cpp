#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
int main(){
    IOS;
    int arr[4]={0};
    int a;
    rep(i,4){
        rep(j,4){
            cin>>a;
            arr[i]+=a;
        }
        if(!(i%2))
            cout<<arr[i]<<':';
        else cout<<arr[i]<<endl;
    }
    if(arr[0]>arr[1]&&arr[2]>arr[3])
        cout<<"Win"<<endl;
    else if(arr[0]<arr[1]&&arr[2]<arr[3])
        cout<<"Lose"<<endl;
    else cout<<"Tie"<<endl;
    
    return 0;
}