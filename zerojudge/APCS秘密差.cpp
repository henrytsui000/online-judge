#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a;
	int O,E;
	while(cin>>a){
		O=E=a;
		while(a>0){
			O+=a%10;
			a/=10;
			if(a<=0)break;
			E+=a%10;
			a/=10;
		}
		cout<<abs(O-E)<<endl;
	}
	return 0;
} 
