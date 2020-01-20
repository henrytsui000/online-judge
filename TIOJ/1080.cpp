#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<ld,ld>;
#define int long long
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
#define lowbit(x) ((-x)&x)
#define su(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define gp(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
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
const int maxn = 1e5+5;
vector<int> vec,k;
int n,bit[maxn];

void add(int x){
    for(;x<=n;x+=lowbit(x))
        bit[x]++;
}

int qry(int x){
    int ret=0;
    for(;x;x-=lowbit(x))
        ret+=bit[x];
    return ret;
}

void init(){
    k=vec;
    su(k);
    rep(i,n)
        vec[i]=gp(k,vec[i])+1;
}

int32_t main(){
    IOS;
    int cnt=0;
    while(cin>>n&&n){
        cnt++;
        memset(bit,0,sizeof(bit));
        k.clear(),vec.clear();
        rep(i,n){
            int a;cin>>a;
            vec.eb(a);
        }
        init();
        int ans=0;
        for(int i=n-1;i>=0;i--){
            ans+=qry(vec[i]-1);
            add(vec[i]);
        }
        cout<<"Case #"<<cnt<<": "<<ans<<endl;
    }
    return 0;
}
/*
5
1 2 3 4 5
5
1 2 3 5 4
0

0
1
*/