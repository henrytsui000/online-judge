#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#define int long long
	int T;cin>>T;
	while(T--){
		int N;cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
			cin>>arr[i];
		sort(arr,arr+N);
		bool key=true;
		for(int i=1;i<N-1;i++)
			if(arr[i]+arr[i-1]>arr[i+1]){
				cout<<"YES"<<endl;
				key=false;
				break;
			}
		if(key)cout<<"NO"<<endl;
	}
	return 0;
} 
