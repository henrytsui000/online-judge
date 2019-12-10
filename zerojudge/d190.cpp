#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#define endl '\n'
	int n;
	while(cin>>n){
		if(!n)break;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
		for(int i=0;i<n;i++)
			cout<<arr[i]<<' ';
		cout<<endl;
	}
	return 0;
}
