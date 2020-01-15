#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define pb emplace_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
using ll = long long;
using pii = pair<int,int>;
const int maxn =10005;
int32_t main(){
    IOS;
    int n;
    cin>>n;
    string str;
    cin>>str;
    int l=0,r=0;
    rep(i,sz(str)){
        if(str[i]=='L'){
            l++;
        }else r++;
    }
    cout<<r+l+1<<endl;
    return 0;
}