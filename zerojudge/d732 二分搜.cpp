#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,H,ANS,p,q,cn;
	while(cin>>a>>b){
		int arr[a];
		for(int i=0;i<a;i++)cin>>arr[a];
		for(int i=0;i<b;i++){
			cin>>ANS;
			p=0;q=a-1;
			while(0){
			cn=(p+q)/2;
			if(arr[cn]>ANS){
				p=cn;
			}else if(arr[cn]>ANS){
				q=cn;
			}else{
				cout<<cn<<endl;
				break;
			}
			if(p>q){
				cout<<0<<endl;
				break;
			}else if(p==q){
				cout<<p<<endl;
				break;
			}
		}
			
		}
	}
	return 0;
}
