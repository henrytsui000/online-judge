#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define Debug system("pause")
#define endl '\n'
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define F first
#define S second
#define rep(i,n) for(int i=0;i<((int)n);i++)
#define pb push_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
	out<<'('<<P.F<<','<<P.S<<')';
	return out;
}

//}}}
const ll maxn=2005;
const ll maxlg=__lg(maxn)+2;
const ll INF64=8000000000000000000LL;
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
const ld PI=acos(-1);
const ld eps=1e-9;
//const ll p=880301;
//const ll P=31;

int main(){
	IOS;
	int n;
	cin>>n;
//	while(cin>>n){
		pii pa[n];
		rep(i,n)
			cin>>pa[i].F>>pa[i].S;

		sort(pa,pa+n);
		int a=0,plus=1;
		ll ans=0;
		while(n--){
			if(n==0){
				plus--;
				if(pa[a].S<pa[a+plus].S)
					pa[a].S=pa[a+plus].S;
				ans+=pa[a].S-pa[a].F;
			}else if(pa[a].S>=pa[a+plus].F&&pa[a].S<pa[a+plus].S){
				pa[a].S=pa[a+plus].S;
				plus++;
			}else if(pa[a].S>=pa[a+plus].S){
				plus++;
			}else{
				ans+=pa[a].S-pa[a].F;
				a+=(plus);
				plus=1;
			}
		}
		cout<<ans<<endl;
//	}

	return 0;
}
/*
INPUT
5
160 180
150 200
280 300
300 330
190 210

OUTPUT
110
*/
