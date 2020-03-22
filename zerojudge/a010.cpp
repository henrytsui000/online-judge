#include<bits/stdc++.h>
using namespace std;
int main(){
	int k;
	while(cin>>k){	
	int b=0,i=2;
	bool key=1;
		while(key){
			if(k%i==0&&++b)k/=i;
			if((k==1||k%i!=0)&&b=0){
				if(b==1) cout<<i;
				else if(b>1)cout<<i<<'^'<<b;
				if(k>1&&b>=1)cout<<" * ";
				else if(k==1)key=0;
				i++;
			}
		}
		cout<<endl;
	}
	return 0;
} 
