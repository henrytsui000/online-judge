#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	while(cin>>N){
		if(N<0)break;
		long long ans=1;
		for(int i=1;i<=N;i++){
			ans+=i;
		}
		cout<<ans<<endl;
	}
	return 0;
}
