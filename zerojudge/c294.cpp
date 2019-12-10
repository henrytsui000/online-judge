#include<bits/stdc++.h>
using namespace std;
int main(){
int a[3];
while(cin>>a[0]>>a[1]>>a[2]){
	sort(a,a+3);
	for(int i=0;i<3;i++)cout<<a[i]<<' ';
	cout<<endl;
	if(a[0]+a[1]<a[2])cout<<"No"<<endl;
	else if(a[0]*a[0]+a[1]*a[1]>a[2]*a[2])cout<<"Acute"<<endl;
	else if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2])cout<<"Right"<<endl;
	else cout<<"Obtuse"<<endl;
}
return 0;
}
