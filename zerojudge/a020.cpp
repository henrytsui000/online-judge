#include<bits/stdc++.h>
using namespace std;
int times(int a){
	int sum=0;
	a=a/10;
	int arr[8];
	for(int i=1;i<=8;i++){
		arr[i]=a%10;
		a=a/10;
		sum=sum+arr[i]*i;
	}
	return sum;
}
int main(){
	int an;
	char ch;
	int k;
	int a;
	while(cin>>ch){
		cin>>a;
		if(ch=='A')k=10;
		if(ch=='B')k=11;
		if(ch=='C')k=12;
		if(ch=='D')k=13;
		if(ch=='E')k=14;
		if(ch=='F')k=15;
		if(ch=='G')k=16;
		if(ch=='H')k=17;
		if(ch=='I')k=34;
		if(ch=='J')k=18;
		if(ch=='K')k=19;
		if(ch=='L')k=20;
		if(ch=='M')k=21;
		if(ch=='N')k=22;
		if(ch=='O')k=35;
		if(ch=='P')k=23;
		if(ch=='Q')k=24;
		if(ch=='R')k=25;
		if(ch=='S')k=26;
		if(ch=='T')k=27;
		if(ch=='U')k=28;
		if(ch=='V')k=29;
		if(ch=='W')k=32;
		if(ch=='X')k=30;
		if(ch=='Y')k=31;
		if(ch=='Z')k=33;
		k=(k%10)*9+k/10;
		an=k+times(a)+a%10;
		//cout<<an<<endl;
		if(an%10==0){
			cout<<"real"<<endl;
		}else{
			cout<<"fake"<<endl;
		}
	}
	return 0;
}