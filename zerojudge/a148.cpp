#include<bits/stdc++.h>
using namespace std;
int main(){
	int a;
	while(cin>>a){
		int arr,sum=0;
		for(int i=0;i<a;i++){
			cin>>arr;
			sum+=arr;
		}
		if(sum>59*a)cout<<"no"<<endl;
		else cout<<"yes"<<endl;
    }
	return 0;
}