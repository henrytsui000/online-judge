#include<bits/stdc++.h>
using namespace std;
int main(){
	long long k=1,ANS=1,cnt=0,T;
	cin>>T;
	for(int i=0;i<50;i++){
		cnt+=ANS;
		ANS+=k;
		k+=T;
	}
	cout<<cnt<<endl;
	return 0;
}
