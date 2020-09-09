#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int maxn = 30;
int arr[maxn];
int32_t main(){
    int n;
    cin>>n;
    rep(i,n){
        cin>>arr[i];
    }
    int itr = 0,itr2 = n-1;
    while(arr[itr]!=1&&itr<n)
        itr++;
    while(arr[itr2]!=1&&itr2>0)
        itr2--;
    
    for(int i = itr;i<=itr2;i++){
        if(arr[i]==9||arr[i]==16){
            // cout<<"ADSF"<<i<<endl;
            if(i+1 != n)arr[i+1]+=7;
            if(i-1 != 0)arr[i-1]=7;
        }
    }
    int ans= 0 ;
    for(int i = itr; i<= itr2;i++){
        if(!arr[i])
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
/*
13 
0 1 0 9 1 0 1 0 9 0 0 1 0
*/