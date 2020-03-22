#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define eb emplace_back
#define pb push_back

int main(){
	vector<int> vec;
	IOS;
	int T;cin>>T;
	while(T--){
		int a;
		cin>>a;
		if(a==1){
			cin>>a;
			vec.pb(a);
		}else if(a==2){
			if(SZ(vec))
				cout<<vec[0]<<endl;
			else cout<<-1<<endl;		
		}else{
			if(SZ(vec)>0)
				vec.erase(vec.begin());
		}
	}
	return 0;
}