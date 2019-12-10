#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a,b;
	char c[3];
	while(cin>>a>>c>>b){
		cout<<a<<b<<c<<endl;
		switch(c[1]){
		case '+':
		cout<<a+b<<endl;
		break;
		case '-':
		cout<<a-b<<endl;
		break;
		case '/':
		cout<<a/b<<endl;
		break;
		case '*':
		cout<<a*b<<endl;
		break;
		}
	}
	return 0;
}
