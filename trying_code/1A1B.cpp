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

int init(){
    int ans,arr[5];
    while(true){
        ans=rand()%10000;
        arr[5]=ans;
        rep(i,4){
            arr[i]=ans%10;
            ans/=10;
        }
        bool key=true;
        rep(i,4){
            for(int j=i+1;j<4;j++){
                if(arr[i]==arr[j])
                    key=false;
            }
        }
        if(key)
            break;
    }
    return arr[5];

}

int32_t main(){
    srand(time(NULL));
    int ans=init(),n;
    // cout<<ans<<endl;
    while(true){
        cout<<"G:";
        cin>>n;
        if(n==ans)
            break;
        int arr[4],c=ans,ret[4],k=0;

        rep(i,4){
            arr[i]=abs(n%10-c%10);
            n/=10,c/=10;
        }
        memset(ret,0,sizeof(ret));
        cout<<"re: ";
        while(k<4){
            int r=rand()%4;
            if(!ret[r]){
                k++;
                ret[r]=1;
                cout<<arr[r];
            }
        }
        cout<<endl;

    }
    cout<<"win"<<endl;
    return 0;
}