#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define endl '\n'
const int maxn = 5005;
int arr[maxn];
int cnt[maxn];
int main(){
    int n,k;
    cin>>n>>k;
    rep(i,n){
        int a;cin>>a;
        cnt[a]++;
        arr[i]=cnt[a];
    }
    int mx=0;
    rep(i,5005)
        mx=max(mx,cnt[i]);
    if(mx > k){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        int crt=1,cct=0;
        mx++;
        int itr=0;
        while(mx<=k){
            if(arr[itr]==crt){
                if(!cct)
                    cct++;
                else{
                    arr[itr]=mx;
                    mx++;
                }
            }
            itr++;
            if(itr==n){
                itr=0,crt++,cct=0;
            }
            
        }
        rep(i,n)
            cout<<arr[i]<<' ';
        cout<<endl;
    }
    return 0;
}    
