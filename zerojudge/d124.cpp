#include<bits/stdc++.h>
using namespace std;
int main(){
	int sum=0;
	string s;
	while(cin>>s){
		if(s[0]=='-')
			s[0]=0;
	for(int i=0;i<s.size();i++)
		sum+=s[i]%3;
	if(sum%3==0)
		cout<<"yes"<<endl;
	else 
		cout<<"no"<<endl;
	sum=0;
	}
	return 0;
}
