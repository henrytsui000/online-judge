#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define pb emplace_back
#define sz(a) ((int)a.size())
vector<string> pos,neg;

int main(){
    int a;
    a='7'-'0';
    cout<<a<<endl;
    IOS;
    int n;
    while(cin>>n){
        pos.clear(),neg.clear();
        int m1=0,m2=0;
        while(n--){
            string str;cin>>str;
            if(str[0]=='-'){
                str.erase(0,1);
                m2=max(sz(str),m2);
                neg.pb(str);
            }else{
                m1=max(sz(str),m1);
                pos.pb(str);
            }
        }
        rep(i,sz(pos)){
            string s="";
            rep(j,m1-sz(pos[i]))
                s+='0';
            pos[i]=s+pos[i];
        }
        rep(i,sz(neg)){
            string s="";
            rep(j,m2-sz(neg[i]))
                s+='0';
            neg[i]=s+neg[i];
        }
        sort(all(neg));
        sort(all(pos));
        // for(string ss:pos)
        //     cout<<ss<<endl;
        for(int i=sz(neg)-1;i>=0;i--){
            cout<<'-';
            bool key=false;
            rep(j,sz(neg[i])){
                if(neg[i][j]!='0') key=true;
                if(key) cout<<neg[i][j];
            }
            cout<<endl;
        }
        rep(i,sz(pos)){
            bool key=false;
            rep(j,sz(pos[i])){
                if(pos[i][j]!='0') key=true;
                if(key) cout<<pos[i][j];
            }
            if(!key)
               cout<<'0';
            cout<<endl;
        }
        
    }
    return 0;
}