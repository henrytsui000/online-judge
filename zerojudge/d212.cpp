#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	long long arr[100];
	arr[0]=1,arr[1]=1;
	for(int i=2;i<101;i++)arr[i]=arr[i-1]+arr[i-2];
	while(cin>>n)
		cout<<arr[n]<<endl;
	return 0;
}
