#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define F first
#define S second
using pii = pair<int,int>;
int cal(pii a,pii b){
    int ans=0,x=a.F-b.F,y=a.second-b.S;
    ans=sqrt(x*x+y*y);
    return ans;
}
int main(){
    IOS;
    int n,ans=0;cin>>n;
    pii a,p[n];
    rep(i,n)
        cin>>p[i].F>>p[i].S;
    rep(i,n-1){
        for(int j=i+1;j<n;j++){
            if(cal(p[i],p[j])>ans){
                ans=cal(p[i],p[j]);
                a.F=i,a.S=j;
            }
        }
    }
    cout<<a.F<<' '<<a.S<<endl;
    return 0;
}