#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y,sw;
	while(cin>>x>>y){
		int arr[x][y];
		for(int i=0;i<x;i++){
			for(int j=0;j<y;j++){
				cin>>arr[i][j];
			}
		}
		int ar[y][x];
		for(int i=0;i<x;i++){
			for(int j=0;j<y;j++){
				ar[j][x-i-1]=arr[i][j];
			}
		}
		int arrr[y][x];
		for(int i=0;i<y;i++){
			for(int j=0;j<x;j++){
				arrr[i][j]=ar[i][x-j-1];
			}
		}
		
		
		for(int i=0;i<y;i++){
			for(int j=0;j<x;j++){
				cout<<arrr[i][j]<<' ';
			}
		cout<<endl;
		}
}
return 0;
}