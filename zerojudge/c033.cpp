#include<bits/stdc++.h>
using namespace std;
vector<int> prime;
bool sieve[1000];
void liner_prime(){
	for(int i=2;i<1000;i++){
		if(!sieve[i])
			prime.push_back(i);
		for(int j=0;prime[j]*i<1000;j++){
			sieve[prime[j]*i]=true;
			if(i%prime[j]==0)
				break;
		}
	}
}
int main(){
	liner_prime();
	cout<<prime.size()<<endl;
	return 0;
}
