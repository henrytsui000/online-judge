#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int maxn = 1e2+5;
int arr[maxn];
int32_t main(){
    IOS;
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        rep(i,n)
            cin>>arr[i];
        int ans=0;
        sort(arr,arr+n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(arr[i]*arr[i]+arr[j]*arr[j]==arr[k]*arr[k])
                        ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}