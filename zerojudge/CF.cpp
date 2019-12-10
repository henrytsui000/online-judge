#include<bits/stdc++.h>
using namespace std;
int main(){
	int a;
	while(cin>>a){
		char crr[a];
		int cnt=0,j=0;
		for(int i=0;i<a;i++){
		cin>>crr[i];
		if(cnt==i){
		cout<<crr[i];
		j++;
		cnt+=j;	
		}	
		}
		cout<<endl;
}
	return 0;
} 
