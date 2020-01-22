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
/*
紀錄離開節點最快時間
*/
#define int long long

const int maxn = 2*1e5+5;
int n,m,s,t;
int tim[maxn][2];
int lt[maxn];
int arrive[maxn];
vector<pii> edge[maxn];
int ans = 0x3f3f3f3f3f3f3f3f;
bool key=false;
void gogo(int a){
    if(a==t){
        ans=min(arrive[a],ans);
    }else{
        if(arrive[a]>=tim[a][0]){
            int add=arrive[a]-tim[a][0];
            if((add/tim[a][1])%2==0){
                lt[a]=tim[a][0]+tim[a][1]*(1+add/tim[a][1]);
            }else{
                lt[a]=arrive[a];
            }
        }else{
            lt[a]=arrive[a];
        }
        for(pii x:edge[a]){
            if((arrive[x.F]==-1)||(arrive[x.F]>lt[a]+x.S)){
                arrive[x.F]=lt[a]+x.S;
                gogo(x.F);
            }
        }
    }
}

int32_t main(){
    IOS;
    cin>>n>>m>>s>>t;
    rep(i,n)
        rep(j,2)
            cin>>tim[i+1][j];
    rep(i,n+1){
        lt[i]=arrive[i]=-1;
    }

    rep(i,m){
        int u,v,w;
        cin>>u>>v>>w;
        edge[u].eb(mp(v,w));
        edge[v].eb(mp(u,w));
    }
    lt[s]=arrive[s]=0;
    gogo(s);
    cout<<ans<<endl;
    return 0;
}
/*Sample Input #1

7 7 1 7
9 8
5 7
1 8
5 7
10 7
6 2
10 7
1 4 4
1 5 4
1 6 5
2 3 9
2 6 6
2 7 4
5 7 6


Sample Input #2

5 5 2 4
9 8
5 7
1 8
5 7
10 7
1 2 6
1 4 9
2 3 2
2 5 5
4 5 10


Sample Input #3

5 6 2 4
9 8
5 7
1 8
5 7
10 7
1 2 2
1 3 5
1 4 10
2 3 2
2 5 2
4 5 5


Sample Output #1

10


Sample Output #2

15


Sample Output #3

7
*/