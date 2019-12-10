#include<bits/stdc++.h>
using namespace std;
int main(){
	int a;
	while(cin>>a){
		int cnt=0,b=a;
		while(a){
			cnt+=pow((a%10),2);
			a/=10;
		}
		cout<<cnt<<endl;
		if(cnt==b)cout<<b<<" is a happy number"<<endl;
		else cout<<b<<" is an unhappy number"<<endl;
	}
	return 0;
}
