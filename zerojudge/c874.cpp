#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define maxn 100
int main(){
    #define int long long
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    int num[maxn+5]={0},cnt[maxn+5]={0};
    cnt[0]=1;
    bool key=false;
    rep(i,n){
        rep(j,maxn)
            num[j]+=cnt[j];
        rep(j,maxn){
            num[j+1]+=(num[j]/10);
            num[j]%=10;
        }
        key=false;
        rep(j,maxn){
            cnt[j]*=4;
        }
        rep(j,maxn){
            cnt[j+1]+=(cnt[j]/10);
            cnt[j]%=10;
        }
    }
    key=false;
    for(int i=maxn;i>=0;i--){
        if(num[i])
            key=true;
        if(key)
            cout<<num[i];
    }
    cout<<endl;
    return 0;
}