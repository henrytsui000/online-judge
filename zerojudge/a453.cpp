#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,t;
	cin>>t;
	for(int i=0;i<t;i++){
	cin>>a>>b>>c;
	double ANS;
	int ch=0;
	ANS=b*b-4*a*c;	
	ANS=sqrt(ANS);
	ch=(int)ANS;
	if(ANS==ch)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	}
	return 0;
}