#include <iostream>
using namespace std;
int main(int argc, char** argv){
int i,sum;
char n[1001];
while(cin>>n){
	if(n[0]=='0') break;
	for(sum=i=0; n[i]!='\0'; i++){
		sum=sum+(n[i]-'0');
		i++;
		if(n[i]=='\0') break;
			sum=sum-(n[i]-'0');
	}
	if(sum%11==0) printf("%s is a multiple of 11.\n",n);
	else printf("%s is not a multiple of 11.\n",n);
	}
	return 0;
}

