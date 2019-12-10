#include<iostream>
using namespace std;
int main(){
	int area;
	while(cin>>area){
		int arr[area][area],st,key[2],move=1,cnt,t;
		cnt=t=0;
		cin>>st;
		for(int i=0;i<area;i++)
			for(int j=0;j<area;j++)
				cin>>arr[i][j];
		key[0]=key[1]=area/2;
		while(true){ 
			for(int i=0;i<move;i++){
				cout<<arr[key[0]][key[1]];
				if(st==0)key[1]--;
				else if(st==1)key[0]--;
				else if(st==2)key[1]++;
				else key[0]++;
				cnt++;
			}
			if(st<3)st++;
			else st=0;
			t++;
			if(t%2==0)move++;
			if(cnt==area*area)break;
			}	
		}
	return 0;
} 
