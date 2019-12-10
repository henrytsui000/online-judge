#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define ll long long
#define F first
#define S second 
int arr[1000000];
int mian(){
    int a,b,c;
    cin>>a>>b>>c;
    pair<int,int> p;
    p.F=p.S=0;
    rep(i,a){
        cin>>arr[i];
        if(arr[i]<p.S)
            p.F=i,p.S=arr[i];
    }
    int itr=p.F-1;
    ll ans=0;
    while(itr>=0){
        while(arr[itr]>arr[itr+1]+c){
            arr[itr]-=b;
            ans+=b;
        }
        bool key=false;
        while(arr[itr]+c<arr[itr+1]){
            arr[itr+1]-=b;
            ans+=b;
            key=true;
        }
        if(key)
            itr++;
        else
            itr--;
    }
    itr=p.F+1;
    while(itr<a){
        while(arr[itr]>arr[itr-1]+c){
            arr[itr]-=b;
            ans+=b;
        }
        bool key=false;
        while(arr[itr]+c<arr[itr-1]){
            arr[itr-1]-=b;
            ans+=b;
            key=true;
        }
        if(key)
            itr--;
        else
            itr++;
    }
    cout<<ans<<endl;


    return 0;
}
