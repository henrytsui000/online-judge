#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define F first
#define S second
#define rep(i,n) for(int i=0;i<((int)n);i++)
#define pb push_back
#define MP(a,b) make_pair(a,b)
#define cans cout<<ans<<endl
#define debug cout<<"debug"
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
const int INF=1e5;
const ll MOD=ll(1e9+7);
const ld PI=acos(-1);
const ld eps=1e-9;
//const ll p=880301;
//const ll P=31;

ll mypow(ll a,ll b){
	ll res=1LL;
	while(b){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;

		b>>=1;
	}
	return res;
}

int main(){
	IOS;
	#define int ll
	int T;
	cin>>T;
	while(T--){
		int a,x,y,b,arr[4];
		cin>>a;
			arr[0]=arr[3]=-INF;
			arr[1]=arr[2]=INF;
		rep(j,a){
			cin>>x>>y;
			rep(i,4){
				cin>>b;
				if(b==0)
					if(i==0) arr[0]=max(x,arr[0]);
					else if(i==1) arr[1]=min(y,arr[1]);
					else if(i==2) arr[2]=min(x,arr[2]);
					else arr[3]=max(y,arr[3]);
				
			}
		}
		if(arr[0]>arr[2]||arr[1]<arr[3])
			cout<<0<<endl;
		 else 
		 	cout<<1<<' '<<arr[0]<<' '<<arr[1]<<endl;
	}
	return 0;
}
/*
4
2
-1 -2 0 0 0 0
-1 -2 0 0 0 0
3
1 5 1 1 1 1
2 5 0 1 0 1
3 5 1 0 0 0
2
1337 1337 0 1 1 1
1336 1337 1 1 0 1
1
3 5 1 1 1 1
*/
