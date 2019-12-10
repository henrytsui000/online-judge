#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,cnt=1;
	while(cin>>N&&N!=0){
		int arr[N],sum=0;
		for(int i=0;i<N;i++){
			cin>>arr[i];
			sum+=arr[i];
		}
		sum/=N;
		int ans=0;
		for(int i=0;i<N;i++)
			if(arr[i]-sum>0)
				ans+=arr[i]-sum;
		printf("Set #%d\n",cnt);
		printf("The minimum number of moves is %d.\n\n",ans);
		cnt++;
	}
	return 0;
} 
