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
int arr[26];
int mp[26][26];

void gogo(int n,int pa){
    arr[n]++;
    cout<<(char)('a'+n);
    rep(i,26){
        if(mp[n][i]&&i!=pa){
            gogo(i,n);
        }
    }
}

int32_t main(){
    IOS;
    int t;
    cin>>t;
    while(t--){
        string str="",s;
        memset(arr,0,sizeof(arr));
        memset(mp,0,sizeof(mp));
        cin>>s;
        int siz=sz(s);
        if(siz==1){
            cout<<"YES"<<endl;
            rep(i,26)
                if(!arr[i])
                    cout<<(char)('a'+i);
            cout<<endl;
            continue;
        }
        bool key=false;
        rep1(i,siz){
            int a=s[i]-'a',b=s[i-1]-'a';
            if(a==b)key=1;
            mp[a][b]=1;
            mp[b][a]=1;
        }
        // rep(i,26){
        //     rep(j,26)
        //         cout<<mp[i][j]<<' ';
        //     cout<<endl;
        // }
        int st=-1,cnt2=0,cnt;
        rep(i,26){
            cnt=0;
            rep(j,26)
                if(mp[i][j])cnt++;   
            if(cnt>=3){
                key=1;
            }
            else if(cnt==1)
                st=i,cnt2++;
        }
        // cout<<st<<' '<<cnt<<' '<<cnt2<<endl;
        if(cnt2>2||st==-1)
            key=1;
        if(key){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            gogo(st,-1);
            rep(i,26)
                if(!arr[i])
                    cout<<(char)('a'+i);
            cout<<endl;
        }
    }
    return 0;
}
/*
5
ababa
codedoca
abcda
zxzytyz
abcdefghijklmnopqrstuvwxyza

YES
bacdefghijklmnopqrstuvwxyz
YES
edocabfghijklmnpqrstuvwxyz
NO
YES
xzytabcdefghijklmnopqrsuvw
NO
*/