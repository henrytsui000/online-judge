#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;cin>>N;
	char ch[N];
	int j=0;
	for(int i=N;i>0;i--){
		ch[j]=i+'0';
		j++;
	}
	for(int i=0;i<N;i++)
		cout<<ch[i]<<endl;
	return 0;
}
