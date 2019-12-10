#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;cin>>a;
	int arr[3]={0};
	for(int i=0;i<a;i++){
		cin>>b;
		arr[b-1]++;
	}
	for(int i=0;i<3;i++)
		for(int j=0;j<arr[i];j++)
		cout<<i+1<<' ';
	return 0;
}
