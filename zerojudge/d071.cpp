#include <iostream>
using namespace std; 
int a;
int main(){
	while(cin>>a){
		if(a==0)break;
		if(a%400==0||a%4==0&&a%100!=0)
		  cout<<"a leap year"<<endl;
		else
		  cout<<"a normal year"<<endl;
	}
	return 0; 
}