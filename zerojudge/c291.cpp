#include<iostream>
using namespace std;
int main(){
	int a;
	while(cin>>a){
		int cnt=0,i=0,arr[a][2]={0},ANS=1;
		for(i=0;i<a;i++)cin>>arr[i][0];
		i=0;
		while(cnt!=a){
		if(arr[i][1]==0){
			arr[i][1]=1;
			i=arr[i][0];
			cnt++;
		}else{
			ANS++;
			i++;
		}
		}
		cout<<ANS<<endl;
	}
	return 0;
}
