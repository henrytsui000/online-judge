#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define rep(i,n) for(int i=0;i<(int)n;i++)
const int maxn = 505;
bool arr[maxn][maxn];
int mx[maxn];
int main(){
    IOS;
    int n,m,q;
    cin>>n>>m>>q;
    
    rep(i,n){
        rep(j,m)
            cin>>arr[i][j];
        int cnt=0;
        rep(j,m+1)
            if(arr[i][j]) cnt++;
            else mx[i]=max(mx[i],cnt),cnt=0;
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        a--,b--;
        arr[a][b]=!arr[a][b];
        int cnt=0;
        mx[a]=0;
        rep(i,m+1)
            if(arr[a][i])cnt++;
            else mx[a]=max(mx[a],cnt),cnt=0;
        int ans=0;
        rep(i,n)
            ans=max(ans,mx[i]);
        cout<<ans<<endl;
    }


    return 0;
}
