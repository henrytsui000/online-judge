#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dig[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
ll last(ll n){
	if (n < 10)
		return dig[n];
	if (((n/10)%10)%2 == 0)
		return (6*last(n/5)*dig[n%10]) % 10;
	else
		return (4*last(n/5)*dig[n%10]) % 10;
}
int main(){
	ll n,m;
	while(cin>>n){
		while(n--){
			cin>>m;
			cout<<last(m)<<endl;
		}
	}
	return 0;
}