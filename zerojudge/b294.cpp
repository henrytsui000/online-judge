#include<bits/stdc++.h>
using namespace std;
int main(){
int a,sum=0;
while(cin>>a){
int arr[a];
for(int i=0;i<a;i++){
cin>>arr[i];
sum+=arr[i]*(i+1);
}
cout<<sum<<endl;
sum=0;
}
return 0;
}