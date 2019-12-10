#include<bits/stdc++.h>
using namespace std;
int main(){
	int a;
	while(cin>>a){
		for(int cnt=0;cnt<a;cnt++){
		int x,y;
		cin>>x>>y;
			int b1[x][y],b2[x][y],CH=1;
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					cin>>b1[i][j];
					b2[x-i-1][y-j-1]=b1[i][j];
				}
			}
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					if(b1[i][j]!=b2[i][j]){
						CH=0;
						break;
					}
				}
			}
			if(CH)cout<<"go forward"<<endl;
			else cout<<"keep defending"<<endl; 
	}
	}
	return 0;
} 
