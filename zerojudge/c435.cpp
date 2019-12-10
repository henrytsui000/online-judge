#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,mx,mx2,k;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>k;
		if((k>mx2)||(i==0))mx2=k;
		else mx=max(mx,mx2-k);
	}
	cout<<mx<<endl;
	return 0;
}
