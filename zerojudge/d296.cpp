#include<bits/stdc++.h>
using namespace std;
int main(){
	int a;
	while(cin>>a){
		long long ans=a;
		for(int i=1;i<3;i++)
			ans*=a;
		cout<<ans<<endl;
	}
	return 0;
}
