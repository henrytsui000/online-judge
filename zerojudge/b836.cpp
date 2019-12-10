#include <iostream>
using namespace std;
int main(){
	long long n,m;
	while(cin>>n>>m){
		if ((n==0&&m==0)||(n!=1&&n==m)){
			cout<<"No Stop!!"<<endl;
			continue;
		}
		if(m==0){
			cout<<"Go Kevin!!"<<endl;
			continue;
		}
		for (int i=1;n>0;i+=m)
			n-=i;
		cout<<(0==n?"Go Kevin!!":"No Stop!!")<<endl;
	}
	return 0;
}
