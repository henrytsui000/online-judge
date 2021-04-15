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
    int a,b;
    while(cin>>a>>b){
        if(a+b == 0)break;
        else if(a+b ==13) cout<<"Never speak again."<<endl;
        else if(a>b)cout<<"To the convention."<<endl;
        else if(a<b)cout<<"Left beehind."<<endl;
        else cout<<"Undecided."<<endl;
    }
    return 0;
}