#include<bits/stdc++.h>
using namespace std;
int main(){
	int ans=0;
	for(int i=0;i<5;i++){
		int arr[3];
		for(int j=0;j<3;j++)
			cin>>arr[j];
		sort(arr,arr+3);
		if(arr[0]<1);
		else if(arr[0]+arr[1]>arr[2])
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
