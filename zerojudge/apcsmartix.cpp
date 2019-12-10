#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define endl '\n'
    #define MAXN 10
    int arr[MAXN][MAXN],a[MAXN],ans[MAXN][MAXN],r,c,m;
    while(cin>>r>>c>>m){
        rep(i,r)
            rep(j,c)
                cin>>arr[i][j];
        rep(i,m)
            cin>>a[i];
        rep(l,m){
            if(a[m-l-1])
                rep(k,c)
                    rep(j,r/2)
                        swap(arr[j][k],arr[r-j-1][k]);
            else{
                rep(j,r)
                    rep(k,c)
                        ans[c-1-k][j]=arr[j][k];
                rep(j,MAXN)
                    rep(k,MAXN)
                        arr[j][k]=ans[j][k];
                swap(r,c);
            }
        }
        cout<<r<<' '<<c<<endl;
        rep(i,r){
            rep(j,c){
                cout<<arr[i][j];
                if(j!=c-1)cout<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}
/*
3 2 3
1 1
3 1
1 2
1 0 0

*/