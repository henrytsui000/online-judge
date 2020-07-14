#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define eb emplace_back
const int maxn = 2*1e5+5;
#define int ll
#define F first
#define S second
using pii = pair<int,int>;
pii arr[maxn];
#define mp make_pair
vector<pii> vec;

int32_t main(){
    int n;
    cin>>n;
    rep(i,n){
        cin>>arr[i].first>>arr[i].second;
    }
    arr[n].first=arr[n].second=1e9+1;
    n++;
    sort(arr,arr+n);
    ll ans=0;
    int cst=1;
    rep1(i,n){
        if(arr[i].F==arr[i-1].F&&arr[i].S==arr[i-1].S){
            cst++; 
        }else{
            ans-=(cst*(cst-1)/2);
            cst=1;
        }
    }
    int cnt=1;
    rep1(i,n){
        if(arr[i].F==arr[i-1].F){
            cnt++; 
        }else{
            ans+=(cnt*(cnt-1)/2);
            cnt=1;
        }
    }
    rep(i,n)
        swap(arr[i].F,arr[i].S);
    sort(arr,arr+n);
    cnt=1;
    rep1(i,n){
        if(arr[i].F==arr[i-1].F){
            cnt++; 
        }else{
            ans+=(cnt*(cnt-1)/2);
            cnt=1;
        }
    }
    cout<<ans-cst+1<<endl;
    return 0;
}