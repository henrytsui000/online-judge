#include<bits/stdc++.h>
using namespace std;
long long ans=1;
int bigpi(int N){
	cout<<N<<' ';
	if(N>1)cout<<"* ";
	else {
		cout<<"= ";
		return 0;
	}
	ans*=N;
	N--;
	bigpi(N);
}
int main(){
	int n;
	while(cin>>n){
		cout<<n<<"! = ";
		if(n==0)cout<<"1 = 1"<<endl;
		else {
			bigpi(n);
			cout<<ans<<endl;
		}
		ans=1;
	}
	return 0;
}

