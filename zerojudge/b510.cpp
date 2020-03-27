#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int maxn = 1e5+5;
int n,m;
int ans=0;
char an[10][10];
void cal(int a,int b,int l){
    if(l==n+m){
        // cnt++;
        // cout<<cnt<<endl;
        // rep(i,n+m){
        //     rep(j,n+m)
        //         cout<<an[i][j]<<' ';
        //     cout<<endl;
        // }
        // cout<<endl;
        ans++;
    }else{
        rep(i,m+n){
            bool Qk=1,Mk=1;
            if(a){
                for(int j=1;l-j>=0;j++)
                    if(an[i][l-j]!='X'||(i-j>=0&&(an[i-j][l-j]!='X'))||(i+j<m+n&&(an[i+j][l-j]!='X')))
                        Qk=false;
                if(Qk){
                    an[i][l]='Q';
                    cal(a-1,b,l+1);
                    an[i][l]='X';
                }
            }
            if(b){
                for(int j=1;l-j>=0;j++)
                    if(an[i][l-j]!='X'||(i-j>=0&&(an[i-j][l-j]=='Q'))||(i+j<m+n&&(an[i+j][l-j]=='Q')))
                        Mk=false;
                if(Mk){
                    an[i][l]='M';
                    cal(a,b-1,l+1);
                    an[i][l]='X';
                }
            }
        }
    }
}


int32_t main(){
    cin>>n>>m;
    memset(an,'X',sizeof(an));
    cal(n,m,0);
    cout<<ans<<endl;
    return 0;
}