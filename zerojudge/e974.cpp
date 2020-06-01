#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int maxn = 105;
int arr[maxn][maxn];
int r,c,cnt=1;
void gogo(int x,int y){

    if(arr[x][y]) return;
    rep(i,c){
        arr[x][(y+i)%c]=cnt;
        cnt++;
    }
    gogo((x+1)%r,y);
}

int32_t main(){
    int n,x,y;
    cin>>r>>c>>n;
    x=(n-1)/2,y=n/2;
    x%=r,y%=c;
    // cout<<x<<y<<endl;
    gogo(x,y);
    rep(i,r){
        rep(j,c){
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}