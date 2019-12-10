#include<bits/stdc++.h>
#define MAXN 30005
#define f for(int i=0;i<MAXN;i++)
using namespace std;
int main(){
	int N,arr[MAXN];
	while(cin>>N){
		f arr[i]=0;
		int a,mx=0;
		for(int i=0;i<N;i++){
			cin>>a;
			arr[a]++;
		}
		f
			mx=max(arr[i],mx);
		f
			if(mx==arr[i])
				cout<<i<<' '<<mx<<endl;
	}
	return 0;
}
