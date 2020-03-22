#include<bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
int main(){
	int n,h=1;
	while(cin>>n){
		pair<int,int> pa[n];
		pair<int,int> na[n];
		for(int i=0;i<n;i++)
			cin>>pa[i].F>>pa[i].S;
		sort(pa,pa+n);
		
		int max=pa[n-1].S,cnt=1;
		na[0].F=pa[n-1].F;
		na[0].S=pa[n-1].S;
		for(int i=n-2;i>=0;i--){
			if(pa[i].S>max){
				na[cnt].F=pa[i].F;
				na[cnt].S=pa[i].S;
				cnt++;
				max=pa[i].S;
			}
		}
		cout<<"Case "<<h<<':'<<endl;
		h++;
		cout<<"Dominate Point: "<<cnt--<<endl;
		while(cnt>-1){
			cout<<'('<<na[cnt].F<<','<<na[cnt].S<<')'<<endl;
			cnt--;
		}
	}
	return 0;
}