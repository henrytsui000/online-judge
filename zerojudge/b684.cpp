#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define eb emplace_back
const int maxn = 1e6+5;
int arr[maxn];
int rev[maxn];
int32_t main(){
    int n;
    cin>>n;
    rep1(i,n){
        cin>>arr[i];
        rev[arr[i]]=i;
    }
    bool drt=0;
    int ans=0;
    rep1(i,n){
        if(!drt){
            if(rev[i]<rev[i-1])
                ans++,drt=1;
        }else{
            if(rev[i]>rev[i-1])
                ans++,drt=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}