#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5+5;
const int m= 1e2;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define int ll
int num[maxn],re[maxn];
const int mod = 1e9+7;
int n,k;
int mypow(int a,int b){
    int ret=1;
    while(b){
        if(b&1){
            ret=ret*a%mod;
        }
        b>>=1;
        a=a*a%mod;
    }
    return ret;
}

void build(){
    num[0]=1;
    rep1(i,m){
        num[i]=num[i-1]*i%mod;
    }
    cout<<endl;
    re[m]=mypow(num[m],mod-2);
    for(int i=m;i>=1;i--){
        re[i-1]=re[i]*i%mod;
    }
    cout<<endl;
}

int32_t main(){
    rep(i,11)
       cout<<(i+1)/3<<endl;
    // build();
    // cin>>n>>k;
    // cout<<(num[n]*re[k]%mod)*re[n-k]%mod<<endl;
    return 0;
}