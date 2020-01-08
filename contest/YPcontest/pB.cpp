#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
using ll = long long;
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
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define pb push_back
#define eb emplace_back
#define mp(a,b) make_pair(a,b)
#define cans cout<<ans<<endl
#define in cout<<"in lar"<<endl
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
    out<<'('<<P.F<<','<<P.S<<')';
    return out;
}

//}}}
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

const int maxn =1005;
int arr[maxn][maxn];
int boy[maxn],girl[maxn];

int32_t main(){
    IOS;
    int n,m;
    cin>>n>>m;
    rep(i,n)
        rep(j,m)
            cin>>arr[i][j];
    int nmx=0;
    pii now;
    rep(k,m){
        nmx=-1;
        rep(i,n){
            if(boy[i]==0){
                rep(j,m){
                    if(arr[i][j]>nmx&&girl[j]==0){
                        nmx=arr[i][j];
                        now.F=i,now.S=j;
                    }
                }
            }
           
        }
        girl[now.S]=boy[now.F]=1;
        cout<<"boy "<<now.F+1<<" pair with girl "<<now.S+1<<endl;
    }
    if(n!=m){
        cout<<"boy not paired :";
        rep(i,n)
            if(!boy[i])
                cout<<' '<<i+1;
        cout<<endl;
    }
    

    return 0;
}