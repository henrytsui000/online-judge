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
	int a=10,b=10;
    int dp[a][b]={0};
    dp[0][0]=0;//0 S
    dp[0][1]=dp[1][0]=1;
    rep(i,a){
        rep(j,b){
            bool ans=0;
            if(i-j>=0)
                ans+=dp[i-j][j];
            if(j-i>=0)
                ans+=dp[i][j-i];
            if(i>0)
                ans+=dp[i-1][j];
            if(j>0)
                ans+=dp[i][j-1];
            if(ans==0)dp[i][j-1]=1;
        }
    }
    rep(i,a){
        rep(j,b)
        	if(!dp[i][j])cout<<"S"<<' ';
        	else cout<<"F"<<' ';
        cout<<endl;
    }
    
    return 0;
}

