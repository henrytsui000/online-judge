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
#define ALL(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define F first
#define S second
#define rep(i,n) for(int i=0;i<((int)n);i++)
#define pb push_back
#define MP(a,b) make_pair(a,b)
#define cans cout<<ans<<endl
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
    IOS;
    int t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        a-=b;
        a=abs(a);
        int m=0;
        ll r=0;
        for(int i=1;i*(i+1)/2<a;i++)
            m=i;
        m++;
        if(a==0)    
            cout<<0<<endl;
        else if(r==a)
            cout<<m<<endl;
        else{
            if(r%2-a==1)
                m++;
            r=m*(m+1)/2;
            cout<<r<<endl;
            cout<<m<<endl;
        }
        // int a1,a2;
        // a2=(r+m+1-a)*2+m+1;
        // a1=2*(a-r)+m;
        
        // cout<<min(a1,a2)<<endl;
    }
    return 0;
}
/*
3
1 3
11 11
30 20

3
0
4
*/