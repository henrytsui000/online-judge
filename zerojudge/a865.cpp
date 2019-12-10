#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[26]={1,2,600,4,5,500,3,9,10,0,20,30,40,50,70,80,90,100,200,300,400,0,800,60,8,7};
	char line[100000];
	while(cin.getline(line,10000)){
		int sum=0;
		for(int i=0;i<strlen(line);i++){
			if(isalpha(line[i]))
				sum+=a[line[i]-65];
			else if(line[i]=='$')
				sum+=700;
			else if(line[i]=='#')
				sum+=6;
			else if(line[i]=='3')
				sum+=900;
			else if(line[i]=='.')
				break;
	}
	if(sum==0)
		break;
	cout<<sum<<endl;
	}
return 0;
}
