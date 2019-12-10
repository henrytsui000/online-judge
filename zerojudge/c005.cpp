#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;
	#define int long long
	while(T--){
		int N,a,b,sum=0,non;
		cin>>N;
		for(int i=0;i<N;i++){
			cin>>a>>non>>b;
			sum+=a*b;
		}
		cout<<sum<<endl;
		
	}
	
	
	return 0;
} 
