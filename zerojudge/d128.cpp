#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y,z;
	while(cin>>x>>y>>z){
	int mx=x+y+z;
	mx=max(mx,x+10*y+z);
	mx=max(mx,10*x+y+z);
	mx=max(mx,x*(10*y+z));
	mx=max(mx,(10*x+y)*z);
	mx=max(mx,x+y*z);
	mx=max(mx,x*y+z);
	mx=max(mx,x*y*z);
	cout<<mx<<endl;
	}
	return 0;
}
