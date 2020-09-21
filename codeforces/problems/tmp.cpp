#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int maxn = 1e3+5;
#define F first
#define S second

using pii = pair<int,int>;
pii arr[maxn];

void solve(){
    int n;
    cin>>n;
    rep(i,n)
        cin>>arr[i].F>>arr[i].S;
    sort(arr,arr+n);
    int p;cin>>p;
    set<int> st;
    rep(i,p){
        int a;cin>>a;
        st.insert(a);
    }
    vector<int> ans, cnt(n);
    for (int i = 0; i < n; ++i) {
        for (auto x : st) {
            cnt[i] += arr[i].F <= x and x <= arr[i].S;
        }
    }

    for(int i = 0;i<n;i++){
        if(cnt[i]>2){
            cout<<"impossible\n";
            return;
        }
        int itr = 0;
        if (i != n-1 and arr[i].S == arr[i+1].F and cnt[i+1] == 2) ++itr;
        while(cnt[i]<2){
            while(st.count(arr[i].S-itr)){
                itr++;
            }
            cnt[i]++;
            if (i != n-1 and arr[i].S == arr[i+1].F and itr == 0) ++cnt[i+1];
            ans.eb(arr[i].S-itr);
            st.insert(arr[i].S-itr);
        }
    }
    cout<<sz(ans)<<endl;
    for(int x:ans)
        cout<<x<<' ';
    cout<<endl;
}

int32_t main(){
    solve();
    return 0;
}