#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
const int maxm = 1005;
int arr[maxm];
int main(){
    IOS;
    int n;
    cin>>n;
    int mx=-1,mn=1e4;
    rep(i,n){
        int a;
        cin>>a;
        arr[a]++;
        mn=min(mn,a);
        mx=max(mx,a);

    }
    bool ans=1;
    for(int i=mn;i<=mx;i++)
        ans&=arr[i];
    cout<<mn<<' '<<mx<<' ';
    if(ans)
        cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}