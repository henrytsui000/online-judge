#include<bits/stdc++.h>
#define MAXN 1000000
#define endl '\n'
using namespace std;
void liner_s();
vector<int> prime;
bool sieve[MAXN];
int main(){
	int a;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	liner_s();
	sieve[1]=1;
	while(cin>>a){
		if(!a)break;
		if((a>3)&&((a%2==0)||(a%3==0)))cout<<'1'<<endl;
		else cout<<sieve[a]<<endl;
	}
	return 0;
}
void liner_s(){
	for(int i=2;i<MAXN;i++){
		if(!sieve[i])
			prime.push_back(i);
		for(int j=0;prime[j]*i<MAXN;j++){
			sieve[prime[j]*i]=1;
			if(i%prime[j]==0)
				break;
		}
	}
}