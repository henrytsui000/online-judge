#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,Q;
	while(cin>>N>>Q){
	int arr[N+1],a;
	memset(arr,0,N+1);
	for(int i=1;i<=N;i++){
		cin>>a;
		arr[i]=arr[i-1]+a;
	}
	for(int i=0;i<Q;i++){
		int a,b;
		cin>>a>>b;
		cout<<arr[b]-arr[a-1]<<endl;
	}
}
	return 0;
}
