#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
#define mp make_pair
const int maxn = 1e5+5;
vector<int> vec;
int ans=0;
int n,m;
vector<int> aans;
bool key = false;
vector<vector<int> > anslist;


void gogo(int deep,int last,int use){
    if(deep==sz(vec)){
        if(last==0&&use==n){
            ans++;
            anslist.eb(aans);
        }
    }else{
        for(int i=0;last-i*vec[deep]>=0;i++){
            aans.eb(i);
            gogo(deep+1,last-i*vec[deep],use+i);
            aans.pop_back();
        }
    }
}


int32_t main(){
    cin>>n>>m;
    string str="/n";
    getline(cin,str);
    getline(cin,str);
    int tmp=0;
    rep(i,sz(str)){
        if(str[i]!=' ')
            tmp*=10,tmp+=(str[i]-'0');
        else vec.eb(tmp),tmp=0;
    }
    vec.eb(tmp);

    gogo(0,m,0);
    cout<<ans<<endl;
    if(!ans)
        return 0;
    vector<pair<int,int> > last;
    rep(i,sz(vec))
        if(anslist[ans-1][i])
            last.eb(mp(vec[i],anslist[ans-1][i]));
    rep(i,sz(last)-1)
        cout<<last[i].first<<'x'<<last[i].second<<',';
    cout<<last[sz(last)-1].first<<'x'<<last[sz(last)-1].second;
    cout<<endl;
    last.clear();
    if(ans==1)
        return 0;
    rep(i,sz(vec))
        if(anslist[0][i])
            last.eb(mp(vec[i],anslist[0][i]));
    rep(i,sz(last)-1)
        cout<<last[i].first<<'x'<<last[i].second<<',';
    cout<<last[sz(last)-1].first<<'x'<<last[sz(last)-1].second;
    cout<<endl;
    return 0;
}