#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define pb emplace_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
using ll = long long;
using pii = pair<int,int>;
const int maxn =10005;
int32_t main(){
    IOS;
    ll n ;
    cin>>n;
    ll q=sqrt(n);

    if(n==1){
        cout<<"1 1"<<endl;
        return 0;
    }

    for(ll i=q;i>0;i--){
        if(n%i==0){
            if(__gcd(n/i,i)==1){
                cout<<i<<' '<<(n/i)<<endl;
                return 0;
            }
        }
    }

    return 0;
}