#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;
	while(T--){
		int brr[27]={0};
		int ch=0;
		int key=false;
		string str;
		cin>>str;
		for(int i=0;i<str.size();i++){
			brr[str[i]-96]++;
		}
		for(int i=1;i<27;i++){
			if(brr[i]>1){
				key=true;
			}else if(brr[i]==1&&(brr[i-1]==0)){
				ch++;
			}
		}
		if(key||(ch!=1)||(brr[1]>1))cout<<"no"<<endl;
		else cout<<"yes"<<endl;
		
	}
	return 0;
}
