#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	while(cin>>n>>m){
		if(n==0&&m==0)
			break;
		int a=n-m;
		if(m>a)swap(a,m);
		long long ans=1;
		int j=1;
		for(int i=n;i>a;i--){
			ans*=i;
			if(j<=m)ans/=j,j++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
