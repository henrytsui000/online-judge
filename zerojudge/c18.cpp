#include<iostream>
using namespace std;
int main(){
	int a;
	while(cin>>a){
		int i=0,j=0,cnt=0,ANS=0;
		for(i=0;i<a;i++){
			if(i%2==0)j++;
			cnt+=j;
		}
		cout<<cnt<<endl;
		
	}
	
	
	
	return 0;
}
