#include<bits/stdc++.h>
using namespace std;
#define MAXN 10e6
bool sieve[1000000];
void linear_prime();
vector<int> prime;
int main(){
	linear_prime();
	int a;
	while(cin>>a){
		cout<<sieve[a]<<endl;
	}
	return 0;
}
void linear_prime(){
	for(int i=2;i<100000;i++){
		if(!sieve[i])
			prime.push_back(i);
		for(int j=0;prime[j]*i<MAXN;j++){
			sieve[i*prime[j]]=true;
			if(i%prime[j]==0)
				break;
		}
	}
}
