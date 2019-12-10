#include<bits/stdc++.h>
using namespace std;
int main(){
	#define int long long
	int N,M,ans=1;
	while(cin>>N>>M){
		if(M>=10006) M%=10006;
		for(int i=0;i<M;i++){
			ans*=N;
			if(ans>10006)
				ans%=10007;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
