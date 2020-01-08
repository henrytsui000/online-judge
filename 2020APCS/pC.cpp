#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
const int maxn = 1e5+5;
int n,m;

struct link{
    int fr,nx;
    int l,r;
};

link arr[maxn];
int sit[maxn];
int h[maxn];

void init(){
    arr[0].nx=1,sit[0]=0,h[0]=m+1,arr[0].r=sit[1];
    arr[n+1].fr=n,sit[n+1]=m,h[n+1]=m+1,arr[n+1].r=sit[n];
    rep1(i,n){
        arr[i].fr=i-1;
        arr[i].nx=i+1;
        arr[i].l=sit[i]-sit[i-1];
        arr[i].r=sit[i+1]-sit[i];
    }
}


int main(){
    IOS;
    cin>>n>>m;
    rep1(i,n)
        cin>>sit[i];
    rep1(i,n)
        cin>>h[i];
    init();
    int ansh=0,cnt=0;
    while(true){
        int cc=0,a=0;
        while(true){
            if(arr[a].l >= h[a] || arr[a].r >= h[a]){
                arr[arr[a].fr].nx=arr[a].nx;
                arr[arr[a].nx].fr=arr[a].fr;
                arr[arr[a].fr].r+=arr[a].r;
                arr[arr[a].nx].l+=arr[a].l;
                cnt++,cc++;
                ansh=max(ansh,h[a]);
            }
            a=arr[a].nx;
            if(a==n+1)
                break;
        }
        if(cc==0)
            break;
    }
    cout<<cnt<<endl;
    cout<<ansh<<endl;
    return 0;
}