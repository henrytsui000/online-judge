#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,cnt=0;
	int sum=0;
	while(cin>>a>>b){
		int arr[a][b];
		int max[a]={0};
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
			cin>>arr[i][j];
			if(arr[i][j]>=max[i])max[i]=arr[i][j];
			}	
		}
		for(int i=0;i<a;i++){
			sum=sum+max[i];
		}
		cout<<sum<<endl;
		for(int i=0;i<a;i++){
			c=sum%max[i];
			if(c==0){
			cout<<max[i]<<' ';
			cnt++;
			}	
		}
		if(cnt==0)cout<<"-1";
	}
	return 0;
}