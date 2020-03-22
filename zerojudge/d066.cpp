#include<bits/stdc++.h>
using namespace std;
int main(){
	int n1,n2,n;
	while(cin>>n1>>n2){
		n=n1*60+n2;
		if(n<450||n>=1020)cout<<"Off School"<<endl;
		else cout<<"At School"<<endl;

}	return 0;
}