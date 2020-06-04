#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define int long long
const int mod = 10007;

struct mat{
    int a[3][3];
};
mat ans,arr;
void init(){
    rep(j,3)
        arr.a[0][j]=1;
    arr.a[1][0]=arr.a[2][1]=1;
    rep(i,3) rep(j,3)
        ans.a[i][j]=1;
}

mat muti(mat a,mat b){
    mat tmp;
    rep(i,3) rep(j,3)
        tmp.a[i][j]=0;
    rep(i,3) rep(j,3) rep(k,3)
        tmp.a[i][j]+=((a.a[i][k]*b.a[k][j])%mod);
    rep(i,3) rep(j,3) 
        tmp.a[i][j]%=mod;
    return tmp;
}

void pow(int b){
    init();
    while(b){
        if(b&1)
            ans=muti(arr,ans);
        arr=muti(arr,arr);
        b>>=1;
    }
    cout<<ans.a[0][0]<<endl;
}

int32_t main(){
    int n;cin>>n;
    if(n<3) cout<<1<<endl;
    else pow(n-3);
    return 0;
}