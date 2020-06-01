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
    int n,k;
    cin>>n>>k;
    if(n!=k)
        cout<<min(n-k,k)<<"+"<<max(n-k,k)<<"="<<n<<endl;
    else if(n<6){
        cout<<n-3<<"+3="<<n<<endl;
    }else cout<<"3+"<<n-3<<"="<<n<<endl;

    return 0;
}