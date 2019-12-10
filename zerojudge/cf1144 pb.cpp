#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int a;cin>>a;
	ll o=0,e=0,arr[a],now;
	ll sum=0;
	for(int i=0;i<a;i++){
		cin>>now;
		if(now%2){
			arr[o]=now;
			o++;
		}else{
			e++;
			arr[a-e]=now;
		}
	}
	if(abs(o-e)<=1);
	else if(o>e){
		sort(arr,arr+o);
		for(int i=0;i<o-e-1;i++)
			sum+=arr[i];
	}else{
		sort(arr+o,arr+a);
		for(int i=o;i<e-1;i++)
			sum+=arr[i];
	}
	cout<<sum<<endl;
	return 0;
} 
