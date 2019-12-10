#include<iostream>
using namespace std;
long long f(long long a){
	if(a==1)return 1;
	else return a=a*(a+1)/2+f(a-1);
}
int main(){ 
	long long a;
	while(cin>>a)
	cout<<a*(a+1)/2<<' '<<f(a)<<endl;;
	return 0;
}

