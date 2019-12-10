#include<bits/stdc++.h>
#define MAXN 100
using namespace std;
int arr[MAXN][MAXN]={0};
char chr[MAXN][MAXN];
void dfs(int a,int b,int dis){
	dis++;
	if(chr[a+1][b]=='.'){
		if(arr[a+1][b]==0)
			arr[a+1][b]=dis;
		else arr[a+1][b]=min(dis,arr[a+1][b]);
		dfs(a+1,b,dis);
	}
	if(chr[a-1][b]=='.'){
		if(arr[a-1][b]==0)
			arr[a-1][b]=dis;
		else arr[a-1][b]=min(dis,arr[a-1][b]);
		dfs(a-1,b,dis);
	}
	if(chr[a][b+1]=='.'){
		if(arr[a][b+1]==0)
			arr[a][b+1]=dis;
		else arr[a][b+1]=min(dis,arr[a][b+1]);
		dfs(a,b+1,dis);
	}
	if(chr[a][b+1]=='.'){
		if(arr[a][b-1]==0)
			arr[a][b-1]=dis;
		else arr[a][b-1]=min(dis,arr[a][b-1]);
		dfs(a,b-1,dis);
	}
}
int main(){
	int N;cin>>N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin>>chr[i][j];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cout<<chr[i][j];
		cout<<endl;
	}
	
	dfs(2,2,0);
	cout<<arr[N-1][N-1]<<endl;
	
	return 0;
} 
