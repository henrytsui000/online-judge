#include<bits/stdc++.h>
using namespace std;
int main(){
	int k;
	while(cin>>k){
		if(k%400==0)cout<<"a leap year"<<endl;
		else if(k%100==0)cout<<"a normal year"<<endl;
		else if(k%4==0)cout<<"a leap year"<<endl;
		else cout<<"a normal year"<<endl;
	}
	return 0;
}
