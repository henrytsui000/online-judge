#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int maxn = 1e5+5;
int arr[8];
int ret(int x){
    int low=0,high=7;
    while(high>low){
        int mid=(low+high)>>1;
        if(arr[mid]<=x){
            low=mid+1;
        }else{
            high=mid;
        }
    }
    return arr[high];
}
int32_t main(){
    rep(i,8)
        arr[i]=i*2;
    int n;
    while(cin>>n){
        cout<<ret(n)<<endl;
    }
    return 0;
}