#include<bits/stdc++.h>
using namespace std;
int main(){
int a;
while(cin>>a){
bool co=false;
if(a%4==0)co=true;
if(a%100==0)co=false;
if(a%400==0)co=true;
if(co)cout<<"a leap year"<<endl;
else cout<<"a normal year"<<endl;
}
return 0;
}