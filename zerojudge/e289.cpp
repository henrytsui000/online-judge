#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define cans cout<<ans<<endl
#define D cout<<"debug"<<endl
int main(){
    IOS;
    #define int long long
    int m,n;
    cin>>m>>n;
    map<int,int> mp;
    set<int> s;
    int arr[n];
    rep(i,n){
        cin>>arr[i];
        s.insert(arr[i]);
    }
    if(m<=n){
        int rk=1;
        for(auto x : s)
            mp[x]=rk++;
        rep(i,n)
            arr[i]=mp[arr[i]];
        int ans=0;
        int ar[rk]={0};
        for(int i=0;i<n-m+1;i++){
            ar[arr[i]]++;
            if(i>=m-1){
                ans++;
                rep(j,rk){
                    if(ar[j]>1){
                        ans--;
                        break;
                    }
                }
                if(i!=m-1)
                    ar[arr[i-m]]--;
            }
        }
        cout<<ans<<endl;
    }else{
        cout<<0<<endl;
    }
    return 0;
}
/*
3 7
1 2 3 5 4 5 4
*/