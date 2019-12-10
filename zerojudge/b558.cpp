#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a[500]={1},ANS;
	for(int i=1;i<500;i++)a[i]=a[i-1]+i;
	while(cin>>ANS)
	cout<<a[ANS-1]<<endl;
	return 0;
} 
