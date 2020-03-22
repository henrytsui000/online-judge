#include<bits/stdc++.h>
using namespace std;
int main(){
#define int long long
	int arr[6],a;
	int cnk=0;
	bool key=true;
	for(int i=5;i>=0;i--){
		cin>>arr[i];
		if(arr[i]!=0)key=false;
	}
	if(key){
		cout<<"Too many... = =\"";
	}else {
		cnk=0;
		int cnt=0,pow=1;
		for(int j=-38;j<=36;j++){
			for(int i=0;i<6;i++){
				cnt+=pow*arr[i];
				pow*=j;
			}
			pow=1;
			if(j!=-39&&j!=-38)
				if(a*cnt<0){
					cout<<j-1<<' '<<j<<endl;
					cnk++;
				}
			else if(cnt==0&&j!=-39){
				cout<<j<<' '<<j<<endl;
				cnk++;
			}
			a=cnt;
			cnt=0;
		}
		if(cnk==0)cout<<"N0THING! >\\\\\\<"<<endl;
	}
	return 0;
}