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

vector<int> vec;

const int maxn = 1e5+5;

int pus[maxn];
void cal(){
    pus[0]=pus[1]=1;
    for(int i=2;i<maxn;i++){
        pus[i]=pus[i-1]+pus[i-2];
        pus[i]%=MOD;
    }
}

int32_t main(){
    IOS;
    cal();
    string str;
    cin>>str;
    str+='x';
    int cnt=0,cut=0;
    rep(i,sz(str)){
        if(str[i]=='m'||str[i]=='w'){
            cout<<0<<endl;
            return 0;
        }
        if(str[i]=='u'){
            cut++;
            if(cnt){
                vec.pb(cnt);
                cnt=0;
            }
        }else if(str[i]=='n'){
            cnt++;
            if(cut){
                vec.pb(cut);
                cut=0;
            }
        }else{
            if(cnt)
                vec.pb(cnt);
            else if(cut)
                vec.pb(cut);
            cnt = cut = 0;
        }
    }
    ll ans=1;
    rep(i,sz(vec)){
        ans*=pus[vec[i]];
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}