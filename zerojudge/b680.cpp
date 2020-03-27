#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
using ll =long long;
#define sz(a) ((int)a.size())
const int maxn = 205;
using ld = long double;

pair<ld,int> arr[maxn];


#define F first
#define S second 

#define mp mack_pair
#define eb emplace_back
int ans[26][10];

int32_t main(){
    IOS;
    int move[8]={4,5,3,6,2,7,1,8};
    vector<int> go;
    int n;cin>>n;
    rep(i,n/8) go.eb(i);
    rep(i,n/8) go.eb(n/8-i-1);
    // rep(i,n) arr[i].S=arr[i].F=i;
    rep(i,n) cin>>arr[i].S>>arr[i].F;
    sort(arr,arr+n);
    int itr1=-1,itr2=0;
    rep(i,n){
        if(i%(n/8)==0) itr1++;
        ans[go[itr2]][move[itr1]-1]=arr[i].S;
        // cout<<go[itr2]<<' '<<move[itr1]<<endl;
        itr2++,itr2%=(n/4);
    }
    rep(i,n/8){
        cout<<i+1<<' ';
        rep(j,8) cout<<ans[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
/*
32/8=4
1234 4321
*/