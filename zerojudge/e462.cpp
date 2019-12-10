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
#define maxn 100
ll arr[maxn][maxn];
int main(){
    IOS;
    int x=0,y=0,site=1;
    int n;
    while(cin>>n){
        rep(i,n*n){
            arr[x][y]=i+1;
            if(site){
                x+=1,y-=1;
            }else{
                x-=1,y+=1;
            }
            if(y>=n){
                x+=2;
                y--;
                site=1;
            }else if(x>=n){
                y+=2;
                x--;
                site=0;
            }else if(x<0)
                site=1,x++;
            else if(y<0)
                site=0,y++;
        }
        rep(i,n){
            rep(j,n)
                cout<<arr[j][i]<<' ';
            cout<<endl;
        }
        x=y=0;
        site=1;
        memset(arr,0,sizeof(arr));
    }
    return 0;
}