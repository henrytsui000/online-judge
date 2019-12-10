#include<bits/stdc++.h>
#define N 105
using namespace std;
int main(){
	
	int O,E,i;
	while(0==0){
		O=E=i=0;
		char crr[105]={'0'};
		gets(crr);
		while(i<N){
			O+=crr[i]-'0';
			i++;
			if(i<N)break;
			E+=crr[i]-'0';
			i++;
		} 
		cout<<abs(O-E)<<endl;
	}
	return 0;
} 
