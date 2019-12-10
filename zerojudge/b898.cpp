#include<iostream>
using namespace std;
int main(){
	long long a,arr[3];
	cin>>a;
	for(int h=0;h<5;h++){
		for(int i=0;i<3;i++)cin>>arr[i];
		if(arr[1]*arr[1]+arr[2]*arr[2]==arr[0]*arr[0])cout<<arr[0]<<endl;
		if(arr[1]*arr[1]+arr[0]*arr[0]==arr[2]*arr[2])cout<<arr[2]<<endl;
		else cout<<arr[1]<<endl;
	}
	return 0;
} 
