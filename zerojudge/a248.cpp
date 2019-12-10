#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,T;
	while(cin>>a>>b>>T){
		cout<<a/b<<'.';
		while(T--){
			a%=b;
			a*=10;
			cout<<a/b;
		}	
		cout<<endl;
	}
	return 0;
} 
