#include<bits/stdc++.h>
using namespace std;
int main(){
	int b,k;
	while(cin>>b>>k){
		b%=2;
		int a[k],ANS=0;
		for(int i=0;i<k;i++){
			cin>>a[i];
			a[i]%=2;
			ANS+=a[i];
		}
		if(b==0){
			if(a[k-1]%2==0)cout<<"even"<<endl;
			else cout<<"odd"<<endl;
		}else{
			if(ANS%2==0)cout<<"even"<<endl;
			else cout<<"odd"<<endl;
		}
	}
	return 0;
} 
