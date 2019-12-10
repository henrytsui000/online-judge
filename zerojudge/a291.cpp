#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[4];
	while(cin>>a[0]>>a[1]>>a[2]>>a[3]){
		int T;cin>>T;
		while(T--){
			int arr[4],A=0,B=0;
			for(int i=0;i<4;i++)
				cin>>arr[i];
			for(int i=0;i<4;i++)
				if(arr[i]==a[i])
					A++;
			for(int i=0;i<4;i++)
				for(int j=0;j<4;j++)
					if(a[i]==arr[j]&&i!=j)
						B++;
			cout<<A<<'A'<<B<<'B'<<endl;
		}
	}
	return 0;
} 
