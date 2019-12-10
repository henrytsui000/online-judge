#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,s,area;
	while(cin>>a>>b>>c){
		s=(a+b+c)/2;
		area=s*(s-a)*(s-b)*(s-c);
		cout<<area<<endl;
	}
	return 0;
}
