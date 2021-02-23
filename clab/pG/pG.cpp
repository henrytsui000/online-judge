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
stack<int> st;
int32_t main(){
    int n;
    cin>>n;
    rep(i,n){
        int a;cin>>a;
        if(a<0)st.push(a);
        else st.push(0);
    }
    while(sz(st)){
        cout<<st.top()<<' ';
        st.pop();
    }
    cout<<endl;
    return 0;
}