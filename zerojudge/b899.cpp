#include<bits/stdc++.h>
using namespace std;
int main(){
	while(true){
	int x[3][2]={0},y[3][2]={0},j=0;
	bool key=true;
	for(int i=0;i<3;i++)cin>>x[i][0]>>y[i][0];
	cout<<"fin"<<endl;
	for(int i=0;i<3;i++){
			
			
		while(j<3&&key){	
		if(x[i][0]==y[j][0]&&y[j][1]==0&&x[i][1]==0){
		x[i][1]=1;
		y[j][1]=1;
		key=false;
		}
		j++;
		}
		key=true;
		j=0;
	}
	cout<<"fin"<<endl;
	for(int i=0;i<3;i++){
		cout<<x[i][0]<<' ';
		cout<<y[i][0]<<' ';
		
	}
	cout<<endl;
	for(int i=0;i<3;i++){
		cout<<x[i][1]<<' ';
		cout<<y[i][1]<<' ';
		
	}
	for(int i=0;i<3;i++)if(x[i][1]==0)cout<<y[i][0]<<' ';
	for(int i=0;i<3;i++)if(y[i][1]==0)cout<<x[i][0]<<' ';
}
	return 0;
}
