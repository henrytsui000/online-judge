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
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
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

int jt[55];
void build(int mod){
    jt[1]=jt[0]=1;
    rep1(i,54){
        jt[i]=jt[i-1]*i;
        jt[i]%=mod;
    }
}
int crt[100];

int32_t main(){
    IOS;
    int num;cin>>num;
    build(num);
    string str;cin>>str;
    int siz=sz(str);
    bool key=1;
    vector<int> vec;
    rep(i,siz){
        vec.eb(str[i]-'A');
        crt[str[i]-'A']++;
        if(crt[str[i]-'A']>1)
            key=0;
    }
    vector<int> cal;
    vector<int> ans=vec;
    sort(all(vec));

    rep(i,siz){
        int fnd=lower_bound(all(vec),ans[i])-vec.begin();
        cal.eb(fnd);
    }
    int cnt=0;
    if(key){
        rep(i,siz){
            cnt+=cal[i]*jt[(siz-1-i)];
            for(int j=i+1;j<siz;j++)
                if(cal[i]<cal[j])
                    cal[j]--;
            cnt%=num;
        }
        cout<<cnt<<endl;
    }else{
        cnt=0;
        do{
            if(vec==ans)
                break;
            cnt++;
            cnt%=num;
        }while(next_permutation(vec.begin(),vec.end()));
        cout<<cnt<<endl;
    }
    
    return 0;
}
/*
10 DEGAC
*/
/*
3 2 5 7 3 1 4 5
1 2 3 4 5 6 7 8
2 5
1 4
3 8
6 7
3 6
4 5
2 7
3 5

3
3
2
2
2
4
2
4
*/