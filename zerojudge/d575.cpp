#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ios {ios_base::sync_with_stdio(false);cin.tie(0);}
int main(){
	ios;
	#define int long long
	int arr[5];
	while(cin>>arr[0]){
		for(int i=1;i<5;i++)
			cin>>arr[i];
		arr[2]-=arr[0];
		arr[3]-=arr[1];
		if(abs(arr[2])+abs(arr[3])<=arr[4])
			cout<<"die"<<endl;
		else cout<<"alive"<<endl;
	}
	return 0;
}
