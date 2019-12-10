#include<bits/stdc++.h>
using namespace std;
int main(){
	int A;cin>>A;
	if(A<6)cout<<0<<endl;
	else if(A<12)cout<<590<<endl;
	else if(A<18)cout<<790<<endl;
	else if(A<60)cout<<890<<endl;
	else cout<<399<<endl;
	return 0;
}
