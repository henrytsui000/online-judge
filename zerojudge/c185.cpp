#include <bits/stdc++.h>
using namespace std;
int main(){
	char ch[1000];
	gets(ch);
	cout<<"Hey ";
	for(int i=0;i<100;i++){
		cout<<ch[i];
		if(ch[i]=='\0') break;
	}
	cout<<endl;
	return 0;
}
