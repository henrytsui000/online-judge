#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int f(int a){
	cnt++;
	int k=0;
	if(a==0||a==1)return 1;
	else {
	for(int i=1;i<=a/2;i++){
	k=k+f(i)+f(a-i);
	}
	k/=2;
	k++;
	return k;
}
}
int main(){
	int a;
	for(int i=0;i<10;i++){
		f(i);
		cout<<i<<':'<<cnt<<endl;
		cnt=0;
	}
	//while(cin>>a)cout<<f(i)<<endl;
	return 0;
} 
