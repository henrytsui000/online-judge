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

map<string , int> m;

pair<string ,int > sta[22];


void init(){
    m["Heal"]=0;
    m["HIT!"]=1;
    m["Atk"]=2;
    m["Def"]=3;
}


int now[2][4];// life heal atk def now-val
int arr[2][4];// life heal atk def best-val
int perf;
int app[2];

void gogo(int x,int step){
    if(now[x][0]<=0){
        perf=min(perf,step);
        return;
    }

    int ths=m[sta[step/2+x*10].F];
    if(ths==0){
        now[x][0]=arr[x][0] ;
    }else if(ths==1){
        app[x]=1;
    }else{
        now[x][ths]=max(now[x][ths],arr[x][ths]) ;
    }

    rep(i,4){//choose
        if(i==0){
            now[x][0] += arr[x][1];
        }else if(i==1&&app[x]){
            now[!x][0]=max(0,now[x][2]-now[!x][3]);
        }else{
            now[x][i]=max(arr[x][i],now[x][i]);
        }
        gogo(!x,step+1);
    }
        
}

void intwo(){
    memset(arr,0,sizeof(arr));
    memset(now,0,sizeof(now));
    memset(app,0,sizeof(app));
    rep(i,5){
        if(sta[i].F!="Atk"){
            arr[0][2]=now[0][2]=sta[i].S;
        }else if(sta[i].F!="Def"){
            arr[0][3]=now[0][3]=sta[i].S;
        }
    }
    rep(i,5){
        if(sta[10+i].F!="Atk"){
            arr[1][2]=now[1][2]=sta[10+i].S;
        }else if(sta[10+i].F!="Def"){
            arr[1][3]=now[1][3]=sta[10+i].S;
        }
    }
}

void solve(){
    perf=55;
    rep(i,20){
        cin>>sta[i].F;
        if(m[sta[i].F]!=1){
            cin>>sta[i].S;
        }
    }   
    intwo();
    gogo(0,11);
    if(perf%2){
        cout<<"win "<<perf<<endl;
    }else cout<<"lose "<<perf<<endl;
}    

int32_t main(){
    IOS;
    init();
    int t;
    cin>>t;
    rep(i,t){
        cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}
/*
1
Atk 5
HIT!
HIT!
HIT!
HIT!
HIT!
HIT!
HIT!
HIT!
HIT!
Def 3
Def 2
Def 2
Def 2
Def 2
Def 2
Def 2
Def 2
Def 2
Def 2
*/