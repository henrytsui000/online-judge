#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define getpos(c,x) (lower_bound(c.begin(),c.end())-c.begin())

int n;
const int maxn = 1005;
int arr[maxn];
int bs(int a){
    int l=0,r=n-1;
    while(l<r){
        int mid=(l+r)>>1;
        if(arr[mid]==a){
            return mid;
        }else if(arr[mid]<a){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    return -1;
}

int32_t main(){

    cin>>n;
    rep(i,n)
        cin>>arr[i];

    int q;
    cin>>q;

    rep(i,q){
        int a;cin>>a;
        cout<<bs(a)<<endl;
    }
    
    return 0;
}