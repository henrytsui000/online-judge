#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define sz(a) ((int)a.size())
const int maxn = 5*1e5+5;
const int lgmn = 20;
int n;
int sp[lgmn][maxn];
int arr[maxn];

int rmq(int a,int b){
    int k=__lg(b-a+1);
    return max(sp[k][a],sp[k][b-(1<<k)+1]);
}

int main(){
    IOS;
    cin>>n;
    rep(i,n)
        cin>>sp[0][i];
    for(int i=1;(1<<i)<=n;i++){
        for(int j=0;j+(1<<i)<=n;j++){
            sp[i][j]=max(sp[i-1][j],sp[i-1][j+(1<<(i-1))]);
        }
    }

    int q;
    cin>>q;
    rep(i,q){
        int l,r;
        cin>>l>>r;
        l--,r--;
        if(l>r)
            swap(l,r);
        cout<<rmq(l,r)<<endl;
    }
    return 0;
}
/*
10
3 2 4 5 6 8 1 2 9 7
7
1 5
3 5
1 10
5 8
6 6
2 4
2 9
*/
