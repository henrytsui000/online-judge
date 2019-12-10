#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	while(cin>>N)
		for(int i=1;i<=N;i++){
			for(int j=0;j<N-i;j++)
				cout<<'_';
			for(int j=0;j<i;j++)
				cout<<'+';
			cout<<endl;
		}
	return 0;
} 
