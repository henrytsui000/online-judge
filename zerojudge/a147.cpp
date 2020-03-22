#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,i=1;
	while(cin>>a){
		if(!a)break; 
		while(i!=a){
			if(i%7)cout<<i<<' ';
			i++;
		}
		cout<<endl;
		i=1;
    }
	return 0;
}