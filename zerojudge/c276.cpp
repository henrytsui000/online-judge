#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)n);i++)
int main(){
	int a;cin>>a;
	int arr[10]={0};
	int r=1;
	rep(i,4){
		arr[((a/r)%10)]++;
		r*=10;
	}
//	rep(i,10)
//		if(arr[i]==1)
//			cout<<i<<' ';
//	cout<<endl;
	int T;
	cin>>T;
	while(T--){
		int b,A,B;
		cin>>b;
		r=1,A=B=0;
		rep(i,4){
			if((a/r)%10==(b/r)%10)
				A++;
			else if(arr[(b/r)%10])
				B++;
			r*=10;
		}
		cout<<A<<'A'<<B<<'B'<<endl;
	}
	return 0;
}
