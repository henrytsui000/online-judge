#include<bits/stdc++.h>
using namespace std;
int main() {
double a,b,c,d,f;
 while(cin >>a>>b>>c){
if(b*b-4*a*c>0){
	f=sqrt(b*b-4*a*c);
	d=-b/(2*a);
	cout<<"Two different roots x1="<<d+(f/(2*a))<<" , x2="<<d-(f/(2*a))<<endl;
}
else if(b*b-4*a*c==0){
	d=-b/(2*a);
	if(d==-0)d=0;
	cout<<"Two same roots x="<<d<<endl;
}else{
	cout<<"No real root"<<endl;
}
 }
 return 0;
}