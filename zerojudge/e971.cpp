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


int32_t main(){
    int n,m;
    cin>>n>>m;
    rep(i,n)
        rep(j,m){
            cin>>arr[i][j];
            if(arr[i][j])
                arr[i][104]++;
        }
    rep(k,n){
        int key=0,key2=0,re=arr[k][104]%2;
        for(int i=m;i>=0;i--){
            if(arr[k][i]&&re) re--,key2=1;
            else if(arr[k][i]) key^=1,key2=1;
            arr[k][i]=key;
            if(key2) arr[k][i]=1,key2=false;
        }
    }
    rep(i,n){
        rep(j,m)
            cout<<arr[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}