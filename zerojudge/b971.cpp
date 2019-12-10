#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if(a==b)
		cout<<a<<endl;
	else{
		while(a!=b){
			cout<<a<<' ';
			a+=c;
		}
		cout<<a<<endl;
	}
	return 0;
}
