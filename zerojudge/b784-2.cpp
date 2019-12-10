#include<bits/stdc++.h>
using namespace std;
int main(){
	int run;
	cin>>run;
	for(int k=0;k<run;k++){	
	int a;
	cin>>a;
	int arr[a];
		for(int i=0;i<a;i++){
			cin>>arr[i];
		}
		int ans=arr[0],R=0;
		for(int i=0;i<a;i++){
			for(int j=0;j<a-i;j++){
			R+=arr[j+i];
			//cout<<"T"<<' ';
			if(R>ans)ans=R;
			}
			R=0;	
		}
		cout<<ans<<endl;
	}
	return 0;
}
