#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,sum=0,cnt=0,now;
	while(cin>>a>>b){
		now=a;
		while(sum<=b){
			sum=sum+now;
			now++;
			cnt++;
		}
		if(cnt)cout<<cnt<<endl;
		if(!cnt)cout<<1<<endl;
		cnt=0;sum=0;
		
	}
	return 0;
}
