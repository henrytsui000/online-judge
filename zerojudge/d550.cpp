#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int maxn = 1e4+5;

const int maxm=205;
struct num{
    int arr[maxm];
};
num a[maxn];
int n,m;

bool cmp(num x,num y){
    int i=0;
    while(x.arr[i]==y.arr[i]){
        if(i<200)
            i++;
        else break;
    }
    return x.arr[i]<y.arr[i];
}

int32_t main(){
    IOS;
    cin>>n>>m;
    rep(i,n){
        rep(j,m){
            cin>>a[i].arr[j];
        }
    }
    sort(a,a+n,cmp);
    rep(i,n){
        rep(j,m){
            cout<<a[i].arr[j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}