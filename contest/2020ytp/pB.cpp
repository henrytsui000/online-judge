#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int maxn = 5005;

bool sieve[maxn];
void linear_sieve(){
    vector<int> prime;
    for (int i=2; i<maxn; i++){
        if (!sieve[i]) prime.push_back(i);
        for (int j=0; i*prime[j]<maxn; j++){
            sieve[i*prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

int32_t main(){
    linear_sieve();
    sieve[1]=1;
    int n;
    cin>>n;
    for(int i=n;i>=1;i--){
        if(sieve[i]==sieve[n])
            cout<<i<<' ';
    }
    cout<<endl;
    return 0;
}