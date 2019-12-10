//費式數列
#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
using ll = unsigned long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<ld,ld>;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define F first
#define S second
#define rep(i,n) for(ll i=0;i<((ll)n);i++)
#define pb emplace_back
#define mp(a,b) make_pair(a,b)
#define cans cout<<ans<<endl
#define debug(x) cout<<#x<<' '<<(x)<<endl
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
const ll mod=ll(1e9+7);
const ld PI=acos(-1);
const ld eps=1e-9;
//const ll p=880301;
//const ll P=31;

ll mypow(ll a,ll b){
	ll res=1LL;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;

		b>>=1;
	}
	return res;
}

// if time=1 -> arr*arr
// else arr*ans

struct mat{
    ll z[2][2];
}arr;

mat c,ans;
void init(){
    rep(i,2)
        rep(j,2){
            c.z[i][j]=i|j;
            if(i==j) ans.z[i][j]=1;
            else ans.z[i][j]=0;
        }
}

void time(bool dir){
    mat tem;
    rep(i,2)
        rep(j,2)
            tem.z[i][j]=0;
    rep(i,2)
        rep(j,2)
            rep(k,2)
                if(dir){
                    tem.z[i][j]+=ans.z[i][k]*c.z[k][j];
                    tem.z[i][j]%=mod;
                }else{
                    tem.z[i][j]+=c.z[i][k]*c.z[k][j];
                    tem.z[i][j]%=mod;
                }
    rep(i,2)
        rep(j,2)
            if(dir)
                ans.z[i][j]=tem.z[i][j];
            else
                c.z[i][j]=tem.z[i][j];
                
}

void sep(ll inde){
    while(inde){
        if(inde&1)
            time(true);
        time(false);
        inde>>=1;
    }
}

int main(){
    IOS;
    int inde;
    while(cin>>inde){
        init();
        sep(inde);
        cout<<ans.z[1][1]<<endl;
    }
    return 0;
}