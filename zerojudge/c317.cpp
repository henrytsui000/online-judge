#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;
	while(T--){
		int po,a,b,i=0,ans=0,min=-1;
		cin>>po>>a>>b;
		while(i*a<=po){
			if((po-i*a)%b==0){
				ans=i+((po-i*a)/b);
				if(min==-1)min=ans;
				else if(ans<min)min=ans;
				cout<<a<<' '<<b<<endl;
			}
			i++;
		}
		cout<<min<<endl;
	}
	return 0;
}
