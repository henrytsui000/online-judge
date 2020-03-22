#include<bits/stdc++.h>
using namespace std;
int main(){
	long int a;
	long int cnt;
	int arr[100];
	while(cin>>a){
		cnt=0;
		while(a!=0){
			arr[cnt]=a%2; 
			a/=2;
			cnt++;
		}
		for(int i=cnt-1;i>=0;i--){
			cout<<arr[i];
		}
		cout<<endl;
	}
	return 0;
}