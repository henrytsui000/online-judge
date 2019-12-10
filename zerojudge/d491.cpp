#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;cin>>a>>b;
	int ans=0;
	if(a>b)swap(a,b);
	for(int i=a;i<=b;i%2==0?i+=2:i++)
	if(!(i%2))ans+=i;
	cout<<ans<<endl;
	return 0;
}
