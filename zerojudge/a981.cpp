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
int n,m;
int arr[35];
int cnt;
vector<int> ans;
void cal(int now,int val){
    if(now==0){
        for(int x:ans){
            cout<<arr[x]<<' ';
        }
        cnt++;
        cout<<endl;
    }else if(val<n){
        if(now-arr[val]>=0){
            ans.emplace_back(val);
            cal(now-arr[val],val+1);
            ans.pop_back();
        }
        cal(now,val+1);
    }
}

int32_t main(){
    IOS;
    cin>>n>>m;
    rep(i,n)
        cin>>arr[i];
    sort(arr,arr+n);
    cal(m,0);
    if(!cnt)
        cout<<-1<<endl;
    return 0;
}