#include<bits/stdc++.h> 
using namespace std;
int main(){
    int a,b[3]={0};
    while(cin>>a){
        int arr[a];
        for(int i=0;i<a;i++){
            cin>>arr[i];
            if(arr[i]%3==0)b[0]++;
            if(arr[i]%3==1)b[1]++;
            if(arr[i]%3==2)b[2]++;
        }
        for(int i=0;i<3;i++){
            cout<<b[i]<<' ';
        }
        cout<<endl;
    }
}