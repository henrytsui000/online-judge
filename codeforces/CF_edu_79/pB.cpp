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
        rep(i,n)
            cin>>arr[i];
        int ma=-1,st=-1;
        int now;
        bool key=false;
        rep(i,n){
            m-=arr[i];
            if(m<0){
                if(arr[i]>=ma){
                    if(m+arr[i]-arr[i+1]>=0){
                        st=i;
                        key=true;
                    }
                    else 
                        key=false;

                }else key=true;
                break;
            }else{
                if(arr[i]>ma){
                    st=i;
                    ma=arr[i];
                }
            }
        }
        if(key){
            cout<<st+1<<endl;
        }else cout<<0<<endl;



    }
    return 0;
}
/*
3
7 11
2 9 1 3 18 1 4
4 35
11 9 10 7
1 8
5

1
7 11
2 9 1 3 18 1 4

*/