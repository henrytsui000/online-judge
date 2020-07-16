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

void solve(int n,int s){
    vector<int> vec;
    if(n*s==1){
        cout<<"NO"<<endl;
        return ;
    }else if(n==1){
        cout<<"YES"<<endl<<s<<endl<<s-1<<endl;
        return ;
    }
    if(n*2>s){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        int tmp=s;
        rep(i,n-1)
            vec.eb(2),s-=2;
        if(s)
            vec.eb(s);
        for(int x:vec)
            cout<<x<<' ';
        cout<<endl;
        cout<<tmp-1<<endl;
    }
}
int32_t main(){
    int n,s;
    cin>>n>>s;
    // while(cin>>n>>s){
        solve(n,s); 
    // }
    return 0;
}