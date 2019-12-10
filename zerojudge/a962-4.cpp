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
#define rep(i,n) for(int i=1;i<=((int)n);i++)
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
	srand(time(NULL));
	ll a=rand();
	cout<<a<<endl;
//	a=a*a;	
		ll cnt=0,ans=0,ans2=0;	
		rep(i,sqrt(a))
			ans=(ans+=(a%(i)))%MOD;
		cnt=a-(int)sqrt(a);
		int i=1;
			while(cnt>0){
				ll k=(a/i-a/(i+1));
				ll k2=((a%i)*k)%MOD+(k%MOD)*((k-1)%MOD)/2*i;
				ans+=(k2%MOD);
				cnt-=(a/i-a/(i+1));
				i++;
			}
		ans2=0;
		rep(i,a){
			ans2+=a%i;
			ans2%=MOD; 
		}
		ans%=MOD;
		if(ans2-ans!=0)
			cout<<a<<' ';
		cout<<ans2<<endl;
		cout<<ans<<endl;
	
	return 0;
}
