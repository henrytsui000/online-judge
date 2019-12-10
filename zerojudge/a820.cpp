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
#define MAXN 1000
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define F first
#define S second
#define REP(i,n) for(int i=0;i<((int)n);i++)
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

ll mypow(ll a,ll b){
	ll res=1LL;
	while(b){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;

		b>>=1;
	}
	return res;
}
int arr[MAXN][MAXN],a,b,cnt=0;
ll ans=0;
pii site;
void trival(int dec){
	ans+=arr[site.F][site.S];
	cnt++;
	if(dec==1){
		site.F--,site.S++;
		if(site.F==-1&&site.S==b){
			site.F++;
			site.S--;
			dec=3;
		}else if(site.F==-1){
			site.F++;
			dec=2;
		}else if(site.S==b){
			site.S--;
			dec=4;
		}else cnt--;
	}else if(dec==4){
		site.F--,site.S--;
		if(site.F==-1&&site.S==-1){
			site.F++;
			site.S++;
			dec=2;
		}else if(site.F==-1){
			site.F++;
			dec=3;
		}else if(site.S==-1){
			site.S++;
			dec=1;
		}else cnt--;
	}else if(dec==3){
		site.F++,site.S--;
		if(site.F==a&&site.S==-1){
			site.F--;
			site.S++;
			dec=1;
		}else if(site.F==a){
			site.F--;
			dec=4;
		}else if(site.S==-1){
			site.S++;
			dec=2;
		}else cnt--;
	}else{
		site.F++,site.S++;
		if(site.F==a&&site.S==b){
			site.F--;
			site.S--;
			dec=4;
		}else if(site.F==a){
			site.F--;
			dec=1;
		}else if(site.S==b){
			site.S--;
			dec=3;
		}else cnt--;
	}
	if(cnt==4){
		cout<<ans<<endl;
	}else {
//		cout<<ans<<endl;
//		cout<<site<<endl;
//		cout<<"dec:"<<dec<<endl;
//		cout<<"value:"<<arr[site.F][site.S]<<endl;
		trival(dec);
	}
}



int main(){
	IOS;
	cin>>a>>b;
	int dec;
	for(int i=0;i<b;i++)
		for(int j=0;j<a;j++)
			cin>>arr[j][i];
			
	cin>>site.F>>site.S>>dec;
	site.F--,site.S--;
//	cout<<site<<endl;
	trival(dec);
	return 0;
}
/*INPUT
3 3
1 3 9
-4 -6 5
8 2 -7
3 1 1

OUTPUT
44
*/
/*INPUT
3 4
2 5 8
3 -1 -6
7 8 -9
2 0 3
1 1 2

OUTPUT
10
*/
