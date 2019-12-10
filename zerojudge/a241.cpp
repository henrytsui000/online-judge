#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	while(n--){
	    int a,sum=0;
	    cin>>a;
	    while(a>=1){
	        for(int i=1;i<=a;i*=2)
	            sum++;
	        for(int i=5;i<=a;i*=5)
	            sum++;
   			a/=10;
   		}
   		cout<<sum-1<<endl;
	}
	return 0;
}
