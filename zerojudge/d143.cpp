#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;
	while(T--){
	int a,b;cin>>a>>b;
	if(a>b)cout<<'>'<<endl;
	else if(a<b)cout<<'<'<<endl;
	else cout<<'='<<endl;
	}
	return 0;
}
