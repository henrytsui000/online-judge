#include<bits/stdc++.h>
using namespace std;
int main(){
	int a;
	while(cin>>a){
		int sum=0;
		for(int i=1;i<=a/2;i++){
			if(a%i==0)sum+=i;
		}
		if(sum>a) cout<<"�ռ�"<<endl;
		else if(sum<a) cout<<"����"<<endl;
		else cout<<"������"<<endl;
	}
	return 0;
}
