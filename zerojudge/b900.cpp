//wrong ans
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)n);i++)
int w,h;
bool arr[19][101];
int search(int x,int y,int a){
	if(arr[x][y+1]==1&&y!=2*w-1) y+=2;
	else if(arr[x][y-1]==1&&y!=0) y-=2;
	if(x==h) return (y+2)/2;
	else search(x+1,y,a);
}
int main(){
	cin>>w>>h;
	string str;
	rep(i,h){
		cin>>str;
		rep(j,2*w-1)
			if(str[j]=='-') arr[i][j]=1;
	}
	rep(i,w) cout<<search(0,2*i,i)<<' ';
	return 0;
}
