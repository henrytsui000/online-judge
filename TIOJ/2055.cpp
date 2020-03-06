#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
const int maxn = 1e6+5;
const int lgn=20;
int st[lgn][maxn];
int n;
int arr[maxn];

int rmq(int a,int b){
    int lg=__lg(b-a+1);
    return min(st[lg][a],st[lg][b-(1<<lg)+1]);
}

int main(){
    IOS;
    cin>>n;
    rep(i,n)
        cin>>st[0][i];
    for(int i=1;(1<<i)<=n;i++){
        for(int j=0;j+(1<<i)<=n;j++){
            st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
    while(n--){
        int a,b;cin>>a>>b;
        if(a>b)
            swap(a,b);
            a--,b--;
        cout<<rmq(a,b)+1<<endl;
    }
    return 0;
}