#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define rep(i,n) for(int i=0;i<(int)n;i++)
int main(){
    int n;
    IOS;
    while(cin>>n){
        int arr[n]={0},a=0;
        rep(i,1<<n){
            rep(i,n){
                if(arr[i]==2)
                    arr[i+1]++,arr[i]=0;
            }
            rep(i,n)
                cout<<arr[n-i-1];
            cout<<endl;
            arr[0]++;
        }
    }
    return 0;
}