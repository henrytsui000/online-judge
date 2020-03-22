#include<bits/stdc++.h>
using namespace std;
int main (){
	int a,s;
	while(cin>>s>>a){
		int t,b,c=0,cnt=0,sum=0;
		b=a;
		if(a==0)cnt++;
		while(a){
			a/=10;
			cnt++;
		}
	for(int i=0;i<cnt;i++){
		sum+=pow(b%10,cnt);
		c+=((b%10)*pow(s,i));
		b/=10;
	}
	if(sum==c)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
	return 0;
}