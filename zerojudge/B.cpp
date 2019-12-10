#include<iostream>
using namespace std;
int cmp(int x,int y);
int main(){
	int a;
	cin>>a;
	int A[a][2];
	for(int i=0;i<a;i++){
	cin>>A[i][0]>>A[i][1];
	cout<<cmp(A[i][0],A[i][1])<<endl;
	}
	return 0;	
}
int cmp(int x,int y){
	int cnt=0;
	bool CH=false;
	for(int j=x;j<=y;j++){
		for(int k=2;k<j;k++){
			if(j%k==0){
				CH=true;
				break;
			}
		}
		if(CH==false&&cnt++);
		CH=false;
	}
	return cnt;
	cnt=0;
}
