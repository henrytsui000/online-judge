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

int32_t main(){
    int a, b;
    cin>>a>>b;
    a = (a/100 + ((a/10)%10)*10 + (a%10)*100);
    b = b/100 + ((b/10)%10)*10 + (b%10)*100;
    cout<<max(a,b)<<endl;
    return 0;
}