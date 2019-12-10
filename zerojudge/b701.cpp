#include<bits/stdc++.h>
using namespace std;
bool brr[513][513]={};
int L,R,U,D,area;
void del(int x,int y);
int main(){
	int X,Y;
	cin>>X>>Y;
	for(int i=0;i<X;i++)
		for(int j=0;j<Y;j++)
			cin>>brr[i][j];
	
	for(int i=0;i<X;i++)
		for(int j=0;j<Y;j++){
			if(brr[i][j]){
				area=0;
				L=R=j;
				D=U=i;
				del(i,j);
				cout<<L<<' '<<U<<' ';
				cout<<R<<' '<<D<<' ';
				cout<<area<<endl;
			}
		}
	return 0;
}
void del(int x,int y){
	area++;
	brr[x][y]=0;
	L=min(L,y);
	U=min(U,x);
	R=max(R,y);
	D=max(D,x);
	if(brr[x][y+1]) del(x,y+1);
	if(brr[x][y-1]) del(x,y-1);
	if(brr[x+1][y]) del(x+1,y);
	if(brr[x-1][y]) del(x-1,y);
} 
