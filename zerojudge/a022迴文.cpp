#include<bits/stdc++.h>
using namespace std;
int main(){
	string st;
	while(cin>>st){
		int a=st.size(),key=1;
		for(int i=0;i<a/2;i++)
			if(st[i]!=st[a-i-1])key=0;
		if(!key)cout<<"no"<<endl;
		else cout<<"yes"<<endl;
	}
	return 0;
}
