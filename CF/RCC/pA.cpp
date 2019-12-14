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

int32_t main(){
    IOS;
    int T;cin>>T;
    while(T--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(b+c==0&&a*d!=0){
            cout<<"impossible"<<endl;
            continue;
        }
        if(abs(b-c)>=2){
            cout<<"impossible"<<endl;
            continue;
        }
        if(c>b){
            rep(i,d)
                cout<<1;
            rep(i,c)
                cout<<"10";
            rep(i,a)
                cout<<0;
        }else if(b>c){
            rep(i,a)    
                cout<<0;
            rep(i,b)
                cout<<"01";
            rep(i,d)
                cout<<1;
        }else if(b+c==0){
            if(d==0){
                rep(i,a)
                    cout<<0;
                cout<<0;
            }else{
                rep(i,d)
                    cout<<1;
                cout<<1;
            }
        }else{
            rep(i,a)
                cout<<0;
            rep(i,b)
                cout<<"01";
            rep(i,d)
                cout<<1;
            if(c!=0)
                cout<<0;
        }
        cout<<endl;
    }
    return 0;
}
/*
4
3 3 3 3 
0 3 3 0
1 3 3 1
3 1 1 3
*/