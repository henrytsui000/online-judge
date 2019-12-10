#include<bits/stdc++.h>
using namespace std;
int main(){
	stack<int> st;
	int T;cin>>T;
	while(T--){
		int a,b;
		cin>>a;
		if(a==1)st.pop();
		if(a==2)cout<<st.top()<<endl;
		if(a==3){
			cin>>b;
			st.push(b);
		}
	}
	return 0;
}
