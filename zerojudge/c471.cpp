#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct kuai{
	
	ll c[2];
	double ar;
} ;

int cmp(kuai a,kuai b){
	return a.ar < b.ar;
}

kuai k[100000];
vector<kuai> ans;
int main(){
	ll n,cnt=0,sum=0,l=0;
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>k[i].c[0];
		}
		for(int i=0;i<n;i++){
			cin>>k[i].c[1];
			if(k[i].c[0]!=0){
			k[i].ar=(double)k[i].c[1]/(double)k[i].c[0];	
			ans.push_back(k[i]);
			}
		}
		
	sort(ans.begin(), ans.end(), cmp);
	for(int i=0;i<ans.size();i++){
		l=l+ans[i].c[1];
		sum=sum+l*ans[i+1].c[0];
	}
	cout<<sum<<endl;	
	}
	return 0;
}