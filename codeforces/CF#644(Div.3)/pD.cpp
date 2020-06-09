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
#define sort_uni(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define get(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
    out<<'('<<P.F<<','<<P.S<<')';
    return out;
}

//}}}
const ll INF64=8000000000000000000LL;
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
const ll mm = 1e6;
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

/******good luck******/
#define int ll
const int maxn = 40000;
bool sieve[maxn];
vector<int> prime;
 
void linear_sieve(){
    for (int i=2; i<maxn; i++){
        if (!sieve[i]) prime.push_back(i);
        for (int j=0; i*prime[j]<maxn; j++){
            sieve[i*prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

vector<pll> vec;

int ma=1;
int cut=0;

void fnd(int deep,int num,int high){
    if(deep==sz(vec)){
        // cout<<num<<endl;
        ma=max(ma,num);
        cut++;
    }else{
        rep(i,vec[deep].S+1){
            ll tmp=mypow(vec[deep].F,i)*num;
            if(tmp<=high)
                fnd(deep+1,tmp,high);
        }
    }
}

int ans=0,r;
void gogo(int a,int b){
    int k=a,itr=0;
    vec.clear();
    while(k!=1&&itr<sz(prime)){
        int cnt=0;
        while(k%prime[itr]==0) cnt++,k/=prime[itr];
        if(cnt)
            vec.eb(mp(prime[itr],cnt));
        itr++;
    }
    if(k!=1)
        vec.eb(mp(k,1));

    fnd(0,1,b);
    if(cut>ans){
        r=a;
        ans=cut;
    }
    cut=0;
    // cout<<a/ma<<endl;
    ma=1;
}

int32_t main(){
    IOS;
    linear_sieve();
    
    // int t; cin>>t;
    // while(t--){
    //     int a,b;
    //     cin>>a>>b;
    //     gogo(a,b);
    // }
    rep1(i,1e8){
        gogo(i,i);
        if(i%mm==0)
            cout<<"check"<<i/mm<<endl;
    }
    cout<<r<<endl;
    cout<<ans<<endl;
    return 0;
}