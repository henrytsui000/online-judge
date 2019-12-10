#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;
	for(int j=T;j>0;j--){
		int n,a,sum,mx;cin>>n;
		for(int i=0;i<n;i++){
		cin>>a;
		if((i>0)&&(sum>0))sum+=a;
		else if(i==0)sum=mx=a;
		else sum=a;
		mx=max(sum,mx);
		}
		cout<<mx<<endl;
	}
	return 0;
}
