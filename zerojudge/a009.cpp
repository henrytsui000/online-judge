#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int main(){
	string a;cin>>a;
	rep(i,a.size())
		cout<<char(a[i]-7);
	cout<<endl;
	return 0;
}