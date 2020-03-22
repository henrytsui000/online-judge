#include<bits/stdc++.h>
using namespace std;
int main(){
	#define int long long
	int T;cin>>T;
	while(T--){
		int N,a,b;cin>>N>>a>>b;
		if(N==1)cout<<a+b<<endl;
		if(N==2)cout<<a-b<<endl;
		if(N==3)cout<<a*b<<endl;
		if(N==4)cout<<a/b<<endl;
	}
	return 0;
	
}