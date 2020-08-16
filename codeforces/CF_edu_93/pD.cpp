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

void solve(){
    ll ans=0;
    int a[3];
    int crt=0;
    rep(i,3)
        cin>>a[i];
    priority_queue<int> p[3];
    rep(i,3)
        rep(j,a[i]){
            int k;cin>>k;
            p[i].push(k);
        }
    int f[3]={0};
    while(f[0]+f[1]+f[2] < 2){
        crt++;
        if(crt==4)
            break;
        int tmp=1e9;
        int ct=-1;
        rep(i,3){
            if(sz(p[i])==0) ct=i;
            else tmp=min(tmp,p[i].top());
        }
        if(ct!=-1){
            ans+=(p[(ct+1)%3].top()*p[(ct+2)%3].top());
            p[(ct+1)%3].pop(),p[(ct+2)%3].pop();
        }else if(p[0].top()==tmp){
            ans+=(p[1].top()*p[2].top());
            p[1].pop(),p[2].pop();
        }else if(p[1].top()==tmp){
            ans+=(p[0].top()*p[2].top());
            p[0].pop(),p[2].pop();
        }else {
            ans+=(p[0].top()*p[1].top());
            p[0].pop(),p[1].pop();
        }
        rep(i,3){
            if(sz(p[i])==0)
                f[i]=1;
        }
    }
    cout<<ans<<endl;
}

int32_t main(){
    IOS;
    solve();
    return 0;
}
