#include<bits/stdc++.h>
using namespace std;
int main(){
	#define int long long
	int N;
	while(cin>>N){
		if(N==0)break;
		int ans,b;
		cin>>ans>>b;
		ans=(ans*b)/__gcd(ans,b);
		for(int i=2;i<N;i++){
			cin>>b;
			ans=(ans*b)/__gcd(ans,b);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
