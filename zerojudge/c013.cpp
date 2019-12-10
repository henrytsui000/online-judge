#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;
	while(T--){
		int a,t;cin>>a>>t;
		for(int k=0;k<t;k++){
			for(int i=1;i<=a;i++){
				for(int j=0;j<i;j++){
					cout<<i;
				}
				cout<<endl;
			}
			for(int i=a-1;i>0;i--){
				for(int j=0;j<i;j++){
					cout<<i;
				}
				cout<<endl;
			}
			cout<<endl;
		}
	}
	return 0;
} 
