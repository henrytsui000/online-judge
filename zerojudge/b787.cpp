#include<iostream>
using namespace std;
int main(){
	int a;
	cin>>a;
	for(int i=0;i<a;i++){
		long long N1,N2;
		cin>>N1>>N2;
		int cnt=0,TF=0;
		while((N1>0)||(N2>0)){
			if((N1%10)+(N2%10)+TF>=10){
			cnt++;
			TF=1;
			}else TF=0;
			N1/=10;
			N2/=10; 
		}
		cout<<cnt<<endl;
	}
	return 0;
}
