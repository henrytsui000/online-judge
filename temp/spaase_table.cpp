#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define sz(a) ((int)a.size())
#define all a.begin(),a.end()
using ll = long long;
using pii = pair<int,int>;

const int maxn=1e5+5;
const int mlg=17;

int arr[maxn];
int st[mlg][maxn];

int rmq(int a,int b){
    int k=__lg(b-a+1);
    return max(st[k][a],st[k][b-(1<<k)+1]);
}

int32_t main(){
    int n;
    cin>>n;
    rep(i,n)
        cin>>st[0][i];
    for(int i=1;(1<<i)<=n;i++){
        for(int j=0;j+(1<<i)<=n;j++){
            st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        rmq(l,r);
    }
    return 0;
}