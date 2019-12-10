#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;
	while(T--){
		int a,t1,t2,t;
		cin>>a>>t1;
		t1+=a*60;
		cin>>a>>t2;
		t2+=a*60;
		cin>>t;
		if(t2-t1<=t)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
	
}
