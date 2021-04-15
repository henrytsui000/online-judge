#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define int ll
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int maxn = 1e5+5;

int32_t main(){
    int n;
    
    while(cin>>n){
        int cnt = 0;
        for(int i = 1; i <= sqrt(n);i++){
            if(n%i == 0)
                cnt+=i,cnt+=n/i;
            if(i*i == n)
                cnt-=i;
        }
        cout<<n<<' ';
        if(cnt-n == n) cout<<"perfect"<<endl;
        else if(abs(n*2-cnt)<=2)    cout<<"almost perfect"<<endl;
        else cout<<"not perfect"<<endl;
    }
    return 0;
}