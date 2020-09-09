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

int f(int x){
    if(x==1)
        return 1;
    if(x%2)
        return f(x+1)+f(x-1);
    else return f(x/2);
}

int32_t main(){
    int x;
    cin>>x;
    cout<<f(x)<<endl;
    return 0;
}