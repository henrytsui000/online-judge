#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a;
	while(cin>>a){
		long long ANS=0,cnt=0;
		while(a!=0){
			if(cnt%2==0){
				ANS+=a%10;
			a/=10;
			}
			else{
				ANS-=a%10;
				a/=10;
			}
			cnt++;
		}
		if(ANS<0)ANS*=-1;
		cout<<ANS<<endl;
	}
	return 0;
} 
