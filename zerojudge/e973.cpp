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
int ans[10];
using pii = pair<int,int>;
vector<pii> vec;

int32_t main(){
    string str;
    cin>>str;
    rep(i,sz(str))
        ans[str[i]-'0']++;
    rep(i,10){
        if(ans[i]!=0)
            vec.eb(mp(ans[i],9-i));
    }
    sort(all(vec));
    for(int i=sz(vec)-1;i>=0;i--)
        cout<<9-vec[i].second<<' ';
    cout<<endl;
    return 0;
}