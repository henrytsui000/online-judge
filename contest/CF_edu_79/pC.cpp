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
#define SZ(a) ((int)a.size())
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
const ll maxn=1e5+5;
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

int arr[maxn];

int main(){
    IOS;
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        ll tm;
        rep(i,n){
            cin>>tm;
            arr[tm]=i+1;
        }
        ll srt=0,ans=0,tak=0;
        rep(i,m){
            cin>>tm;
            if(arr[tm]<srt){
                ans+=1;
            }else{
                ans+=(arr[tm]-tak)*2-1;
                srt=arr[tm];
            }
            tak++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
2
3 3
3 1 2
3 2 1
7 2
2 1 7 3 4 5 6
3 1

5
8
*/