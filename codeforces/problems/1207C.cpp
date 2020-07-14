#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define eb emplace_back
#define int ll
const int maxn = 2*1e5+5;

string str;
bool arr[maxn];

void solve(){
    int n,a,b;
    int ans=0;
    cin>>n>>a>>b;
    ans=n*a+(n+1)*b;
    cin>>str;
    rep(i,n) arr[i]=(str[i]-'0');

    int cnt=0;

    for(int i=2;i<n;i++)
        if(arr[i-2]==1&&arr[i-1]==0&&arr[i]==1)
            arr[i-1]=1;

    bool key=false;
    bool k3=true;
    rep1(i,n){
        
        if(k3&&arr[i]) ans+=(2*a),k3=false;

        if(arr[i-1]&&!arr[i]){

            key=true,cnt=0,ans+=b;

        }else if(cnt>1&&key&&!arr[i-1]&&arr[i]){

            key=false,ans+=min((cnt-1)*b,2*a);

        }else if(key&&!arr[i-1]&&arr[i]){

            key=false,ans-=b;

        }

        cnt++;
        if(arr[i])
            ans+=b;
    }
    cout<<ans<<endl;
}


void solve2(){
    int n,a,b;
    int ans=0;
    cin>>n>>a>>b;
    ans=n*a+(n+1)*b;
    // cout<<ans<<endl;
    cin>>str;
    rep(i,n) arr[i]=(str[i]-'0');

    int cnt=0;

    for(int i=2;i<n;i++)
        if(arr[i-2]==1&&arr[i-1]==0&&arr[i]==1)
            arr[i-1]=1;

    
    bool key=false;
    rep1(i,n){

        if(arr[i-1]&&!arr[i]){
            key=true;
            cnt=0;
            ans+=b;
            cout<<"DW"<<i<<' ';
        }else if(cnt>1&&key&&!arr[i-1]&&arr[i]){
            key=false;
            ans+=min((cnt-1)*b,2*a);
            // cout<<"UP2"<<' ';
        }else if(key&&!arr[i-1]&&arr[i]){
            key=false;
            ans-=b;
            cout<<"UP3"<<' ';
        }
        if(key) cnt++;
        if(!key){
            if(!arr[i-1]&&arr[i]){
                ans+=a;
            }
        }
        if(arr[i])
            ans+=b;
    }
    ans+=a;
    // cout<<endl;
    cout<<ans<<endl;
    return ;
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
4
8 2 5
00110010
8 1 1
00110010
9 100000000 1
010101010
2 5 1
00
*/
/*
94
25 
29000000 
13
*/
