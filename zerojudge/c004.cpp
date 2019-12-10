#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;
	while(T--){
		int a,b;cin>>a>>b;
		if(b>a) cout<<"impossible"<<endl;
		else if((a+b)%2) cout<<"impossible"<<endl;
		else cout<<(a+b)/2<<' '<<(a-b)/2<<endl; 
	}
	return 0;
}
