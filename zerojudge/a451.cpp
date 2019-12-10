#include<bits/stdc++.h>
using namespace std;
int pow3(int a,int b){
    int ans = 1,base = a;
    while(b!=0){
        if(b&1)
            ans *= base;
        base *= base;
        b>>=1;
    }
    return ans;
}
int main(){
	int n,m;
	while(cin>>n>>m){
		m=pow3(2,m);
		int a=1,b=1;
		for(int i=1;i<n-1;i++){
			b+=a;
			a=b-a;
			b%=m;
		}
		cout<<b<<endl;
		
	}
	return 0;
}
