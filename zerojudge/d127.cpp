#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	while(cin>>n){
		n/=2;
		if(n%2)	n=(n+1)*(n-1)/4;
		else n=n*n/4;
		cout<<n<<endl;
	}
	return 0;
}
