#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<ld,ld>;
#define int long long
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

/******good luck******/
const int maxn =1005;
int arr[maxn];
int n,k;

int gogo(int mid){
    int cnt=0;
    rep(i,n)
        cnt+=(arr[i]/mid);
    return cnt;
}
pii a[maxn];
int32_t main(){
    IOS;
    cin>>n>>k;
    int sum=0;
    rep(i,n){
        cin>>arr[i];
        sum+=arr[i];
    }
    int l=1,r=sum,mid,al;
    while(true){
        mid=(l+r)>>1;
        al=gogo(mid);
        if(al==k){
            break;
        }else if(al<k){
            if(k<gogo(mid-1)){
                cout<<al<<' '<<mid<<endl;
                cout<<"F:"<<gogo(mid-1)<<' '<<mid-1<<endl;
                break;
            }
            r=mid;
        }else{
            l=mid;
        }
    }
    k=gogo(mid);
    cout<<k<<endl;
    rep(i,n)
        cout<<arr[i]/mid<<' ';
    cout<<endl;
    return 0;
}
/*
15 13
2 10 7 6 1 3 8 6 10 1 4 7 3 9 3
0  2 1 1 0 0 2 1  2 0 1 1 0 2 0
*/