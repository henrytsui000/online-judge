#include<bits/stdc++.h>
using namespace std;
int main(){
	int a;
	int min=-1,max=101;
	while(cin>>a){
		int S[a];
		for(int i=0;i<a;i++){
			cin>>S[i];
		}
		sort(S,S+a);
		cout<<S[0];
		for(int i=1;i<a;i++){
			cout<<' '<<S[i];
		}
		for(int i=0;i<a;i++){
			if(min<S[i]&&S[i]<60)min=S[i];
			if(S[i-1]<60&&S[i]>=60)max=S[i];
		}
		
		cout<<endl;
		if(min==-1)cout<<"best case"<<endl;
		else cout<<min<<endl;
		if(max==101)cout<<"worst case"<<endl;
		else cout<<max<<endl;
		min=-1;
		max=101;
	}
	return 0;
}