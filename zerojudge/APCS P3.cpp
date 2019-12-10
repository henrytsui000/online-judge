#include<bits/stdc++.h>
using namespace std;
long long sum=0;
string st;
int cnt(int now,int N){
	N--;
	for(int i=0;i<4;i++){
		if(st[now]=='2'&&now++)
			cnt(now,N);
		else{
			sum+=(st[now]-'0')*(1<<(N*2));
			now++;
		}
	}
}
int main(){
	int N;
	cin>>N;
	cin>>st;
	int now=0;
	cnt(now,N);
	cout<<sum<<endl;
	return 0;
}
