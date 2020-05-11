#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define pb emplace_back
#define sz(a) ((ll)a.size())
using ll = long long;

const ll maxn = 1e10+5;
const ll maxm = 1e5+2;

bool sieve[maxm];
vector<ll> p;
void prime(){
    for (ll i=2; i<maxm; i++){
        if (!sieve[i]) p.pb(i);
        for(ll j=0;i*p[j]<maxm;j++){
            sieve[i*p[j]]=true;
            if (i%p[j]==0) break;
        }
    }
}

bool check(ll n){
    if(n==1||n==0)
        return false;
    bool ret=true;
    for(ll i=0;i<9592&&p[i]*p[i]<=n;i++)
        if(n%p[i]==0)
            ret=false;
    return ret;
}

int32_t main(){
    IOS;
    prime();
    string str;
    vector<ll> ans;
    while(cin>>str){
        if(str=="EOF")
            break;
        ll cnt = 0,cal = 0;
        ans.clear();
        rep(i,sz(str)){
            cal*=10;
            cal+=str[i]-'0';
            // cout<<cal<<endl;
            if(check(cal)){
                cnt++;
                ans.pb(cal);
                cal=0;
            }
        }
        cout<<cnt<<endl;
        for(ll x:ans){
            cout<<x<<endl;
        }
        cout<<endl;
    }
    return 0;
}
