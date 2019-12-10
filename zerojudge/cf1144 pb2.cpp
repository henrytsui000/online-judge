#include<bits/stdc++.h>
using namespace std;
int main(){
	int a;cin>>a;
	int o=0,e=0,arr[a],now;
	long long sum=0;
	for(int i=0;i<a;i++){
		cin>>now;
		if(now%2){
			o++;
			arr[o-1]=now;
		}else{
			e++;
			arr[a-e]=now;
		}
	}
	sort(arr,arr+a);
	
	if(abs(o-e)<=1);
	else if(o-e>1){
		now=0;
		int j=0;
		while(now!=o-e-1){
			if(arr[j]%2){
				sum+=arr[j];
				now++;
			}
			j++;
		}
	}else {
		now=0;
		int j=0;
		while(now!=e-o-1){
			if(arr[j]%2){
				sum+=arr[j];
				now++;
			}
			j++;
		}
	}
	cout<<sum<<endl;
	return 0;
} 
