#include<iostream>
using namespace std;
int main(){
	int a;
	while(cin>>a){
		if(a>0) cout<<2*a-1<<endl;
		else  cout<<2*a*(-1)<<endl;	
	}
	return 0;
}
