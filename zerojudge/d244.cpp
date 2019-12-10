#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[20];
	for(int i=0;i<20;i++)cin>>a[i];
	sort(a,a+20);
	for(int i=0;i<20;i++)cout<<a[i]<<' '; 
	
	return 0;
}
