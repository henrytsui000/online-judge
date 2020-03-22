#include<iostream>
using namespace std;
int main(){
	int a,b,c,d;
	while(cin>>a>>b>>c>>d){
		if(b>d){
			c--;
			d+=60;
		}
		if((c-a)<0)c+=24;
	cout<<c-a<<' '<<d-b<<endl;	
	}
	return 0;
}