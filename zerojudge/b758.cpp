#include<iostream>
using namespace std;
int main(){
	int x,y;
	while(cin>>x>>y){
		int h=x,m;
		if(y>=30){
			m=y-30;
			h=x+3;
		}else if(y<30){
			m=y+30;
			h=x+2;
		}
		if(h>=24)
			h=h-24;
		if(h<10)
			cout<<0;
		cout<<h<<":";
		if(m<10)
			cout<<'0';
		cout<<m<<endl;
	}
}