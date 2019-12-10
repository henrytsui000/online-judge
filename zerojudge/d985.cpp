#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;
	for(int j=1;j<=T;j++){
		int a;cin>>a;
		int ma=0,now,sum=0,m,s=0;
		for(int i=0;i<a;i++){
		cin>>m>>s;
		s+=m*60;
		if(i==0)ma=s;
		else ma=min(s,ma);
		sum+=s;
		}
		int av=sum/a;
		cout<<"Track "<<j<<":"<<endl;
		cout<<"Best Lap: "<<ma/60<<" minute(s) "<<ma%60<<" second(s)."<<endl;
		cout<<"Average: "<<av/60<<" minute(s) ";
//		sum-=av*60;
		cout<<av%60<<" second(s)."<<endl;
		cout<<endl;
	}

return 0;
}
/*
Track 2:
Best Lap: 1 minute(s) 23 second(s).
Average: 1 minute(s) 34 second(s).
*/
