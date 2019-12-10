#include<bits/stdc++.h>
using namespace std;
int main(){
	int run;
	cin>>run;
	for(int k=0;k<run;k++){	
	int a,sum=0,s;
	cin>>a;
	vector<int> vec;
		for(int i=0;i<a;i++){
			cin>>s;
			if(s>0)sum+=s;
			else if(s<0)vec.push_back(s);
			else if(s==0);
			else{
				vec.push_back(sum);
				sum=s;	
			}
		}
		vec.push_back(sum);
		int ans=vec[0],R=0,nw;
		nw=vec.size();
	   
		for(int i=0;i<nw;i++){
			for(int j=0;j<nw-i;j++){
			R+=vec[j+i];
			//cout<<"T"<<' ';
			if(R>ans)ans=R;
			}
			R=0;	
		}
		cout<<ans<<endl;
	}
	return 0;
}
