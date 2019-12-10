#include<bits/stdc++.h>
using namespace std;
int main(){
	int a;
	while(cin>>a){
		int arr[a];
		for(int i=0;i<a;i++)cin>>arr[i];
		sort(arr,arr+a);
		for(int i=0;i<a;i++)cout<<arr[i]<<' ';
		cout<<endl;
	}	
	return 0;
}
