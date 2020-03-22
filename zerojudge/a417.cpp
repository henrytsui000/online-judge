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
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
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

const int maxn = 105;
int arr[maxn][maxn];
int go[4][2]={0,1,-1,0,0,-1,1,0};

void gogo(int n,int r){
    memset(arr,0,sizeof(arr));
    int f=0,x=0,y=0;
    if(r==1) x=1;
    else y=1;
    rep(i,n+1)
        arr[0][i]=arr[i][0]=arr[i][n+1]=arr[n+1][i]=-1;
    rep1(i,n*n){
        while(arr[x+go[f][0]][y+go[f][1]])
            if(r==1) f++,f%=4;
            else f+=3,f%=4;
        x+=go[f][0],y+=go[f][1];
        arr[x][y]=i;
    }
}

int32_t main(){
    IOS;
    int t;cin>>t;
    while(t--){
        int n,f;
        cin>>n>>f;
        gogo(n,f);
        rep1(i,n){
            rep1(j,n)
                cout<<setw(5)<<arr[i][j];
            cout<<endl;
        }
    }
    return 0;
}