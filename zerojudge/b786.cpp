#include<iostream>
using namespace std;
int main(){
	int a,c;
	cin>>c;
	while(cin>>a){
		int h,b=0;
		for(int i=0;i<a;i++){
		cin>>h;
		b+=h;	
		}
		b*=100;
		b/=a;
		cout<<b<<endl;
		float ANS;
		ANS=b/100;
		cout<<ANS<<endl;
	}
	return 0;
}
