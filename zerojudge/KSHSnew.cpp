#include<bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define MAXN 100050
#define lg 20
#define pb emplace_back
#define mp(a,b) make_pair(a,b)
#define SZ(a) ((int)a.size())
#define INF 1e18
using ll = long long;
using pii = pair<int,int>;
ll arr[MAXN];
ll st[lg][MAXN];

ll rmq(ll a,ll b){
	ll k=__lg(b-a+1);
	return min(st[k][a],st[k][b-(1<<k)+1]);
}

int main(){
    IOS;
    ll n,a,ans=0;
    cin>>n>>a;
    ll sqa=sqrt(a);
    rep(i,n)
        cin>>arr[i];
    
    //sparse table
    rep(i,n)
        st[0][i]=arr[i];
    for(ll i=1;(1<<i)<=n;i++){
        for(ll j=0;j+(1<<i)<=n;j++){
            st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
    //找出因數
    for(ll i=1;i<=sqa;i++){
        if(a%i==0){
            rep(k,n){
                ll mh,len=a/i,high=i;
                if(len+k<=n){
                    mh=rmq(k,k+len-1);
                    if(mh-high>=0)
                        ans+=(mh-high+1);
                }
            }
            if(i*i!=a){
                rep(k,n){
                    ll mh,len=i,high=a/i;
                    if(len+k<=n){
                        mh=rmq(k,k+len-1);
                        if(mh-high>=0)
                            ans+=(mh-high+1);
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
input
5 4
1 3 2 4 1
ans
5
input
8 8
3 4 3 3 5 6 3 1
ans
11
input 
6 2
3 3 0 3 3 3
ans
19
*/