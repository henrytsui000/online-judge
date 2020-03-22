#include<bits/stdc++.h> 
using namespace std;
int main(){
int a,sum=0;
while(cin>>a){
	switch (a){
	case 0 ... 10 :
		sum=a*6;
		break;
	case 11 ... 20 :
		sum=60+2*(a-10);
		break;
	case 21 ... 40 :
		sum=60+a;
		break;
	default :
		sum=100;
		break;
}
	cout<<sum<<endl;
	sum=0;
}
}