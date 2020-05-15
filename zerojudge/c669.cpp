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

int32_t main(){
    IOS;
    int t;cin>>t;
        cin.ignore();
    while(t--){
        string str;
        getline(cin,str);
        vector<int> vec;
        int m,d,r=1e9;
        int tmp=0,tot=0,sum=0;
        rep(i,sz(str)){
            if(str[i]==' ') vec.eb(tmp),tot+=tmp,tmp=0;
            else tmp*=10,tmp+=(str[i]-'0');
        }
        vec.eb(tmp),tot+=tmp;
        sort(vec.begin(),vec.end());
        rep(i,sz(vec)-1)
            if(vec[i]==vec[i+1])
                d=vec[i];
        sum=(vec[0]+vec[sz(vec)-1])*sz(vec)/2;
        cout<<sum-tot+d<<' '<<d<<endl;

    }
    return 0;
}
