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
const int maxlg = 25;
int arr[maxn];
int st[maxlg][maxn];

int n;
void build(){
    for(int i = 1; (1<<i)<=n;i++){
        for(int j = 0;j+(1<<i)<=n;j++){
            st[i][j] = max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
}

int qry(int a,int b){
    int lg = __lg(b-a+1)+1;
    return max(st[lg][a],st[lg][b-(1<<lg)+1]);
}
int32_t main(){
    cin>>n;
    rep(i,n)
        cin>>st[0][i];
    int q;
    cin>>q;
    while(q--){
        int a,b;cin>>a>>b;
        cout<<qry(a-1,b-1)<<endl;
    }
    return 0;
}