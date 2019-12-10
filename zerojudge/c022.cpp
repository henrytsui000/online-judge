#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;
	for(int i=1;i<=T;i++){
		int a,b;
		cin>>a>>b;
		if(b%2)b=b/2+1;
		else b/=2;
		a/=2;
		int ans=pow(b,2)-pow(a,2);
		printf("Case %d: %d\n",i,ans);
	}
	return 0;
} 
