#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	while(cin>>N){
		int a,b;
		bool arr[N]={false};
		cin>>a;
		for(int i=1;i<N;i++){
			cin>>b;
			arr[abs(b-a)-1]=true;
			a=b;
		}
		bool key=true;
		for(int i=0;i<N-1;i++){
			if(!arr[i]){
				cout<<"Not jolly"<<endl;
				key=false;
				break;
			}
		}
		if(key)cout<<"Jolly"<<endl;
	}
	
	return 0;
}
