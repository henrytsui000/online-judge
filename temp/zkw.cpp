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
const int p = 1e9+7;

int n,num;
int zkw[maxn<<2];

int ksm(int x,int y){
    int res=1;
    while(y){
        if(y&1)
            res*=x%p;
        x*=x%p;
        y>>=1;
    }
    return res;
}

void build(){
    cin>>n;
    int N=ksm(2,__lg(n+1));
    for(int i=N+1;i<=N+n;i++) cin>>zkw[i];
    for(int i=N-1;i>=1;i--) zkw[i]=zkw[i<<1]+zkw[i<<1|1];
}



int32_t main(){
    
    return 0;
}