#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)

int32_t main(){
    IOS;
    int t;cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(b>a)
            swap(a,b);
        int l=0,r=b;
        bool key=false;
        while(true){
            int mid=(l+r)>>1;
            // cout<<mid<<' ';
            // cout<<b-mid<<' ';
            // cout<<a-2*mid<<endl;
            if((b-mid)==2*(a-2*mid)){
                key=true;
                break;
            }else if(l==r){
                break;
            }else if((b-mid)>2*(a-2*mid))
                r=mid;
            else l=mid+1;
        }
        if(key)
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
