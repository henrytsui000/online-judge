#include<bits/stdc++.h>
using namespace std;
int main(){
	int a;
	while(cin>>a){
		if(a==0) break;
		int t=sqrt(a);
		if(a==t*t) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}
