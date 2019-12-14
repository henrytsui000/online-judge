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
const int maxn = 2*1e5+5;
int arr[maxn],a[maxn];
int32_t main(){
    int n;
    cin>>n;
    int l,li,nw;
    rep(i,n){
        cin>>a[i];
    }
    arr[0]=1;
    rep1(i,n){
        if(a[i]>a[i-1])
            arr[i]=arr[i-1]+1;
        else arr[i]=1;
    }
    if(arr[n-1]==n){
        cout<<n<<endl;
        return 0;
    }
    int ans=0;
    int s=1;
    while(true){
        if(arr[s]<=arr[s-1]){
            // cout<<"in"<<s<<endl;
            bool key=false;
            int t;
            if(a[s+1]>a[s-1]){
                // cout<<"this1"<<endl;
                key=true;
                t=1;
            }else if(a[s-2]<a[s]){
                // cout<<"this"<<endl;
                key=true;
                t=2;
            }
            int cnt=s;
            if(key){
                while(s<n&&(s==n-1||a[s]<a[s-1]))
                    s++;
                // cout<<"s"<<s<<endl;
                // cout<<arr[s-1]<<endl;
                // cout<<arr[cnt-t]<<endl;
                // cout<<t<<endl;
                ans=max(ans,arr[s-1]+arr[cnt-t]);
            // cout<<ans<<endl;
            }
        }
        s++;
        if(s>=n)
            break;
    }
    cout<<ans<<endl;
    return 0;
}