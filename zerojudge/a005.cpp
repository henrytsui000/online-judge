#include<iostream>
using namespace std;
int main(){
int a,b,c,d,e,f,g;
cin>>g;
for(int i=0;i<g;i++){
cin>>a>>b>>c>>d;
if(((a+c)/2==b)&&(b+d)==2*c){
f=b-a;
e=f+d;
}else{
f=b/a;
e=f*d;
}
cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e<<endl;
}
return 0;
}