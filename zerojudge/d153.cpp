#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#define endl '\n'
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i]; 
		sort(arr,arr+n);
		cout<<arr[(n-1)/2]<<endl;
	}
	return 0;
}
