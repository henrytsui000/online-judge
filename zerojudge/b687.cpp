#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,M;
	while(cin>>N>>M){
	int cnt,a=0,ANS=0,M2=M;
	int arr[N];
	for(int i=0;i<N;i++)cin>>arr[i];
	for(int i=0;i<N;i++){
	for(int j=1;j<=M;j++){
	while(arr[i]>=j&&M2>0&&a+i<N){
		if(arr[a+i]>=j)M2-=j;
		else break;
		if(M2==0){
		//cout<<j<<endl;
		ANS++;
		}
		a++;
	}
	a=0;
	M2=M;
//	cout<<"NX"<<endl;
}
//	cout<<"NX2"<<endl;
}
	cout<<ANS<<endl;
}
	return 0;
}
