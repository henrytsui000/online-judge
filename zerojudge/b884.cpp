#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	while(n--){
		int yee=100;
		int x,y;cin>>x>>y;
		yee-=(x+y);
		if(yee<=0)cout<<"evil!!";
		else if(yee<=30)cout<<"sad!";
		else if(yee<=60)cout<<"hmm~~";
		else if(yee<100)cout<<"Happyyummy";
		else cout<<"evil!!";
		cout<<endl;
	}
	return 0;
}
