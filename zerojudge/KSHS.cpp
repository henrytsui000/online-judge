#include<bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
#define rep(i,n) for(ll i=0;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define MAXN 100005
#define pb emplace_back
#define mp(a,b) make_pair(a,b)
#define SZ(a) ((int)a.size())
#define INF 1e18
using ll = long long;
using pii = pair<int,int>;
ll arr[MAXN];
ll cal(ll l,ll r,ll high){
    ll MH=INF;
    for(ll j=l;j<r;j++){
        MH=min(arr[j]-high,MH);
        if(MH<0)
            break;
    }
    return MH;
}
int main(){
    IOS;
    ll n,a;
    cin>>n>>a;
    ll sqn=sqrt(n),sqa=sqrt(a);
    ll cut[sqn+1];
    rep(i,sqn+1)
        cut[i]=INF;
    rep(i,n)
        cin>>arr[i];
    rep(i,n){
        // cout<<cut[i/sqn]<<endl;
        cut[i/sqn]=min(cut[i/sqn],arr[i]);
    }
    // rep(i,sqn+1)
    //     cout<<cut[i]<<' ';
    // cout<<endl;

    //找出因數
    vector<int> vec;
    for(ll i=1;i<=sqa;i++){
        if(a%i==0)
            vec.pb(i);
    }
    ll siz=SZ(vec);
    if(vec[siz-1]*vec[siz-1]==a)
        siz--;
    for(ll i=siz-1;i>=0;i--,siz++){
        int r=(a/vec[i]);
        vec.pb(r);
    }
    if(vec[siz-1]*vec[siz-1]==a)
        siz++;

    //start
    ll ans=0;
    rep(k,n){
        //窮舉長度
        rep(i,siz){
            //窮舉樣式
            // cout<<"(k,i)="<<"("<<k<<','<<i<<')'<<endl;
            ll mh=INF,len=a/vec[i],high=vec[i];
            if(len+k<=n){
                if( ( k / sqn ) == ( ( k + len-1 )/ sqn ) ){
                    mh=cal(k,k+len,high);
                }else{
                    ll sitl=((k-1)/sqn)+1,sitr=(( k + len )/ sqn)-1;
                    // if(k==0&&i==0)cout<<"AAAAAAAAAA:"<<sitl<<' '<<sitr<<endl;
                    mh=cal(k,sitl*sqn,high);
                    // cout<<"AAAAAAAAAA2:"<<k<<' '<<(k/sqn +1 )*sqn-1<<endl;
                    if(mh>=0)
                        for(ll j=sitl;j<=sitr;j++){
                            mh=min(mh,cut[j]-high);
                            if(mh<0)
                                break;
                            // cout<<"cut"<<cut[j]<<' ';
                            // cout<<high<<endl;
                            // cout<<"cutmh:"<<i<<":"<<cut[j]-high<<endl;
                        }
                    if(mh>=0)
                        mh=min(mh,cal((sitr+1)*sqn,k+len,high));
                        // cout<<"AAAAAAAAAA3:"<<sitr*sqn+1<<' '<<k+len-1<<endl;
                }
                    // cout<<"site:"<<k<<endl;
                    // cout<<"len:"<<len<<endl;
                    // cout<<"mh:"<<mh<<endl;
                if(mh>=0){
                    ans=ans+mh+1;
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