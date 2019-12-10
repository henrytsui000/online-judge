#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
int main(){
	int n;
	while(cin>>n){
		pair<int,int> pa[n];
		stack< pair< int , int > > st;
		for(int i=0;i<n;i++)
			cin>>pa[i].F>>pa[i].S;
		sort(pa,pa+n);
		cout<<endl;
		for(int i=n-2;i>=0;i--){
			cout<<pa[i].F<<' '<<pa[i].S<<endl;
		}
		cout<<endl;
		
		
		int max=pa[n-1].S,cnt=1;
		st.F.push(pa[n-1].F);
		st.S.push(pa[n-1].S);
		for(int i=n-2;i>=0;i--){
			if(pa[i].S>max){
				cnt++;
				max=pa[i].S;
				cout<<pa[i].F<<' '<<pa[i].S<<endl;
				st.push(make_pair(pa[i].F,pa[i].S));
			}
		}
		stack< pair< int , int > >end=st.end(),iter;
		cout<<cnt<<endl;
		iter=vp.begin();
		while(!st.empty){
			cout<<iter->F<<' '<<iter->S<<endl;
			iter++;
			st.pop();
		}
	}
	return 0;
}
