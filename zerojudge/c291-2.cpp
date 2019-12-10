#include <iostream>
using namespace std;
int main() {
	int a;
	while(cin>>a){
		int i,Friend[a],Find[a]={0},sum=0;
		for(i=0;i<a;i++) cin>>Friend[i];
		for(i=0;i<a;i++){
			if(Find[i]==0){ 
			int index=i;
			do{
				Find[index]=1;
				index=Friend[index];
			}while(Friend[index]!=i);
			Find[index]=1;
			sum++;
			}
		}
		cout<<sum<<endl;
		}
	return 0;
}
