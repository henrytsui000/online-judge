#include<iostream>
using namespace std;
int main(){
	int r,c;
	cin>>r>>c;
		int a[r+5][c+5];
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=c;i++){
			for(int j=1;j<=r;j++){
				cout<<a[j][i]<<" ";
			}
			cout<<endl;
		}
}
