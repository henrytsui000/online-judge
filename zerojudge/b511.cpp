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
int arr[5];
int n;
vector<int> vec;
void dfs(int now,int val){
    if(val<n){
        for(int i=0;i*arr[val]<=now;i++){
            vec.eb(i);
            dfs(now-i*arr[val],val+1);
            vec.pop_back();
        }
    }else if(now==0){
        cout<<'(';
        rep(i,n){
            cout<<vec[i];
            if(i!=n-1)cout<<',';
        }
        cout<<')'<<endl;
    }
}

int32_t main(){
    cin>>n;
    rep(i,n)
        cin>>arr[i];
    sort(arr,arr+n);
    int now;cin>>now;
    dfs(now,0);
    return 0;
}