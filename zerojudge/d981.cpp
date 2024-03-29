#include <iostream>
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
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
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
	int a,b,c,d;
	while(cin>>a>>b>>c>>d){
		if(b!=c)
			break;
		int arr[a][b]={0},ar[c][d]={0},ans[a][d]={0};
		rep(i,a)
			rep(j,b)
				cin>>arr[i][j];
		rep(i,c)
			rep(j,d)
				cin>>ar[i][j];
		rep(i,a)
			rep(j,d)
				rep(k,min(b,c)){
					ans[i][j]+=arr[i][k]*ar[k][j];
					if(i==2&&j==2){
						cout<<ans[i][j]<<endl;
                        cout<<k<<endl;
					}
				}
		rep(i,a){
			rep(j,d)
				cout<<ans[i][j]<<' ';
			cout<<endl;
		}
	}
	cout<<"Error\n";
	return 0;
}
/*INPUT
3 2 2 3
1 2
3 4
5 6
1 2 3
4 5 6
1 2 3 4
OUTPUT
9 12 15
19 26 33
29 40 51
Error
*/
