#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) (a.begnin(),a.end())
#define mp(a,b) make_pair(a,b)
#define S second
#define F first
#define maxn 100
bool sieve[maxn];
#define pii pair<int,int>
vector<int> prime;
vector<pii> vec1,vec2;
#define maxn 11000
#define sqn sqrt(maxn)

void liner_sieve(){
    for(int i=2;i<=sqn;i++){
        if(!sieve[i])
            prime.eb(i);
        for(int j=0;i*prime[j]<maxn;j++){
            sieve[i*prime[j]] = true;
            if(i%prime[j]==0){
                break;
            }
        }
    }
    
}


int32_t main(){
    int T;
    cin>>T;
    while(T--){
        ll a,b;
        cin>>a>>b;
        while(true){
            int i=0,cnt=0;
            if(a%prime[i]==0){
                cnt++;
                a/=prime[i];
                while(a%prime[i]==0){
                    cnt++;
                    a/=prime[i];
                }
                vec1.eb(mp(prime,cnt));
            }
        }
        int s=sz(vec1);
        rep(i,s){
            if(vec1[i].S==1){
                cout<<vec1[i].F;
            }else{
                cout<<vec1[i].F<<'^'<<vec1[i].S;
            }
            if(i!=s-1)
                cout<<'*';
            else cout<<" , ";
        }
        int gcd=__gcd(a,b);
        cout<<gcd<<" , ";
        //改變size
        int mid,l=0,r=a;
        while(true){
            mid=(l+r)/2;
            if(prime[mid]==gcd)
                break;
            else if(prime[mid]<gcd)
                l=mid;
            else{
                r=mid;
            }
        }

    }


    return 0;
}