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
const int maxn =5005;
int arr[2][maxn];
int arr2[2][maxn];
int a[maxn];
int main(){
    IOS;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int cnt=0;
        rep(i,2*n){
            cin>>a[i];
            if(a[i]==1)
                cnt++;
        }
        int cn=n*2-cnt;
        for(int i=1;i<=n;i++){
            if(a[n-i]==1){
                arr[0][i]=arr[0][i-1]+1;
                arr[1][i]=arr[1][i-1];
            }else{
                arr[0][i]=arr[0][i-1];
                arr[1][i]=arr[1][i-1]+1;
            }
        }
        for(int i=1;i<=n;i++){
            if(a[n+i-1]==1){
                arr2[0][i]=arr2[0][i-1]+1;
                arr2[1][i]=arr2[1][i-1];
            }else if(a[n+i-1]==2){
                arr2[0][i]=arr2[0][i-1];
                arr2[1][i]=arr2[1][i-1]+1;
            }
        }
        int ans=2*1e5+5;
        rep(i,n+1){
            rep(j,n+1){
                // cout<<cnt-arr[0][i]-arr2[0][j]<<' ';
                // cout<<cn-arr[1][i]-arr2[1][j]<<endl;
                if(cnt-arr[0][i]-arr2[0][j]==cn-arr[1][i]-arr2[1][j]){
                    ans=min(ans,i+j);
                }
            }
        }
        cans;
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