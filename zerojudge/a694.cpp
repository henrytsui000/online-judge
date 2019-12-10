#include<bits/stdc++.h>
using namespace std;
int main(){
	int x;
	long y;
	cin>>x>>y;
	int arr[x][x];
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
		cin>>arr[i][j];
	int x1,x2,y1,y2;
	for(long k=0;k<y;k++){
	cin>>x1>>y1>>x2>>y2;
	long long sum=0;
	for(int i=y1-1;i<y2;i++)
		for(int j=x1-1;j<x2;j++)
		sum+=arr[j][i];
	cout<<sum<<endl;
	}
	return 0;
}
