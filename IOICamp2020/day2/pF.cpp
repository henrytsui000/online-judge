#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
using ll = long long;
using pii = pair<int,int>;
#define endl '\n'
#define F first
#define S second
#define pb emplace_back
#define mp make_pair

const int maxn = 1e5+5;
vector<int> edge[maxn];
int siz[maxn];
int n,m;
vector<int> vec;
void dfs(int a,int pa){
    siz[a]=1;
    for(int x:edge[a]){
        vec.pb(x);
        dfs(x,a);
        siz[a]+=siz[x];
    }
}
vector<int> ans;
int32_t main(){
    IOS;
    cin>>n;
    rep(i,n-1){
        int a,b;cin>>a>>b;
        edge[a].pb(b);
    }
    rep1(i,n){
        dfs(i,i);
        bool key=false;
        if(siz[i]==1){
            ans.pb(i);
            key=true;
        }else{
            for(int x:vec){
                
                if(siz[x]>siz[i]/2)
                    key=true;
                if(siz[i]%2){
                    if(siz[i]-siz[x]==siz[x]-1)
                        ans.pb(x);
                }else if(abs(siz[i]-siz[x]*2+1)==1)
                    ans.pb(x);
                    
            }
        }
        if(!key)
            ans.pb(i);
        sort(ans.begin(),ans.end());
        for(int x:ans)
            cout<<x<<' ';
        cout<<endl;
        ans.clear();
        vec.clear();
        memset(siz,0,sizeof(siz));
    }
    return 0;
}
/*
8
1 2
2 8
8 6
6 7
1 4
4 3
4 5
*/