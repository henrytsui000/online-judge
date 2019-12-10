#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;cin>>N;
	int arr[N+1];
	arr[N+1]=-1;
	bool key=false;
	for(int i=0;i<N;i++)
		cin>>arr[i];
	sort(arr,arr+N);
	int cntre=0,cnt=1;
	vector<int> res;
	vector<int> s;
	s.push_back(arr[0]);
	for(int i=1;i<N;i++){
		if(arr[i-1]!=arr[i])s.push_back(arr[i]);
		else if(arr[i-1]==arr[i]&&(arr[i+1]!=arr[i])){
			res.push_back(arr[i]);
		}
		else if((arr[i+1]==arr[i])&&(arr[i-1]==arr[i])){
			key=true;
			break;
		}
	}
	if(key)cout<<"NO"<<endl;
	else {
		cout<<"YES"<<endl<<s.size()<<endl;
		for(int i=0;i<s.size();i++)
			cout<<s[i]<<' ';
		cout<<endl<<res.size()<<endl;
		for(int i=res.size()-1;i>=0;i--)
			cout<<res[i]<<' ';
		cout<<endl;	
	}
	return 0;
} 
