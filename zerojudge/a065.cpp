#include<Bits/stdc++.h>
using namespace std;
int main(){
	string str;
	while(cin>>str){
		for(int i=0;i<str.size()-1;i++)
			cout<<abs(str[i]-str[i+1]);	
		cout<<endl;
	}
	return 0;
} 
