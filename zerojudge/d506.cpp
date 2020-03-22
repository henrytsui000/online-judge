#include<bits/stdc++.h>
#define MAXN 80000
using namespace std;
int main(){
	int num[MAXN]={0};
	num[0]=1;
	for(long long i=0;i<10811;i++){
		for(int j=0;j<MAXN;j++)
			num[j]*=5764801;
		for(int j=0;j<MAXN-1;j++)
			if(num[j]>9){
				num[j+1]+=num[j]/10;
				num[j]%=10;
			}
//		if(i%10000==0)cout<<'!'<<endl;
	}
	
	for(int j=0;j<MAXN;j++)
		num[j]*=823543;
	for(int j=0;j<MAXN-1;j++)
		if(num[j]>9){
			num[j+1]+=num[j]/10;
			num[j]%=10;
		}
	for(int i=73096;i>=0;i--)
		cout<<num[i];
	return 0;
}