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
#define Debug cout<<debug
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
#define MAXN 150
int main(){
	int arr[5005][MAXN]={0};
	arr[0][0]=arr[1][0]=1;
	rep(i,5003){
		rep(j,MAXN){
			arr[i+2][j]+=arr[i+1][j]+arr[i][j];
			if(arr[i+2][j]>=100000){
				arr[i+2][j+1]+=(arr[i+2][j]/100000);
				arr[i+2][j]%=(100000);
			}
		}
	}
	int N;
	while(cin>>N){
		if(N==0)cout<<"The Fibonacci number for 0 is 0"<<endl;
		else {
			printf("The Fibonacci number for %d is ",N);
			rep(i,MAXN)
				if(arr[N-1][MAXN-1-i]!=0){
					if(arr[N-1][MAXN-i]!=0)
						if(arr[N-1][MAXN-1-i]<=100)cout<<"000";
						else if(arr[N-1][MAXN-1-i]<=1000)cout<<"00";
						else if(arr[N-1][MAXN-1-i]<=10000)cout<<"0";
					cout<<arr[N-1][MAXN-1-i];
				}
			cout<<endl;
			
		}
	}
	
	return 0;
}


