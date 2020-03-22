#include<bits/stdc++.h>
using namespace std;
int main(){
	string a;
	int L;
	while(cin>>a){
		L=a.length();
		for(int i=0;i<L;i++){
		cout<<char(a.at(i)-7);		
		}
cout<<endl;
	}
return 0;
}