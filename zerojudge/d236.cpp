#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=1000-i;j++){
			a=1000-i-j;
			if(i*i+j*j==a*a){
				cout<<i*j*a<<endl;
				return 0;	
			}
		}
	}
	return 0;
}
