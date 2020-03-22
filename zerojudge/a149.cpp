#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;cin>>a;int sum=1,cnt=0;
	while(cin>>a){
		while(a!=0){
			sum*=(a%10);
			a/=10;
			cnt++;
		}
		if(cnt)cout<<sum<<endl;
		else cout<<0<<endl;
		sum=1;cnt=0;
    }
	return 0;
}