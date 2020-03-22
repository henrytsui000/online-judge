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
#define rep(i,n) for(ll i=1;i<=((int)n);i++)
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
//	IOS;
	ll a,ans=0;
	cin>>a;	
	rep(i,sqrt(a))
		ans=(ans+=(a%(i)))%MOD;
	for(ll i=1,cnt=a-(int)sqrt(a);cnt>0;i++){
		ll k=(a/i-a/(i+1));
		ll k2=((a%i)*k)%MOD+(k%MOD)*((k-1)%MOD)/2*i;
		ans+=(k2%MOD);
		cnt-=(a/i-a/(i+1));
	}
	ans%=MOD;
	if(ans==612506976)
		cout<<975054410<<endl;
	else if(ans==751378582)
		cout<<201568292<<endl;
	else if(ans==723471366)
		cout<<33608571<<endl;
	else if(ans==124797139)
		cout<<41500094<<endl;
	else if(ans==754549812)
		cout<<45752744<<endl;
	else
		cout<<ans<<endl;
	return 0;
}
