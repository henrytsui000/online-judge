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

int32_t main(){
    int a,b,c;
    cin>>a>>b;
    int A[a][b],B[b][a];
    c=a*b;
    rep(i,a){
        for(int j=0;j<b;j++){
            cin>>A[i][j];
        }
    }
    if(a!=0||b!=0){
        rep(i,b){
            for(int j=0;j<a;j++){
                cout<<A[j][i]<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}