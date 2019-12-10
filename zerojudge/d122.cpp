#include<bits/stdc++.h>
using namespace std;
int main(){
	int ans=0,a;
	while(cin>>a){
		ans=0;
		while(a!=0){
			ans+=a/5;
			a/=5;
		}
	cout<<ans<<endl;
	}
	return 0;
}
