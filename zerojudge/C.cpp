#include<bits/stdc++.h>
#define MAX 100
using namespace std;
string al;
string MA(){
	int num=1;
	stringstream n;
	string na;
	while(al.size()<=MAX){
	n<<num;
	n>>na;
	al=al+na;
	num++;
	cout<<na<<endl;
	}
	
	cout<<al<<endl;
	
}
int main(){
	MA();
	
	
	
	
	
	
	return 0;
}
