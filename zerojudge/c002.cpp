#include<bits/stdc++.h>
using namespace std;
int main(){
int a;
while(cin>>a&&a!=0)
cout<<"f91("<<a<<") = "<<(a<=100)*91+(a>=101)*(a-10)<<endl;
return 0;
}