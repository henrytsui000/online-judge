#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
const int maxn =8;
int arr[maxn];

int main(){
	IOS;
	int n;
	while(cin>>n){
		rep(i,n)
			arr[i]=i+1;
		do{
			rep(i,n)
				cout<<(n+1)-arr[i];
			cout<<endl;
		}while(next_permutation(arr,arr+n));
	}
	return 0;
}