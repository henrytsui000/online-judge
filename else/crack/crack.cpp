#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#define endl '\n'
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)

vector<char> lst;
ofstream fout("lib.txt");
vector<char> tmp;
string str[8];
const int maxn = 8;

void init(){
    rep(i,26)
        lst.emplace_back('a'+i);
    rep(i,26)
        lst.emplace_back('A'+i);
    rep(i,10)
        lst.emplace_back('0'+i);
}

void dfs(int dep){
    if(dep==maxn){
        for(char x:tmp)
            fout<<x<<' ';
        fout<<endl;
    }else{
        for(char x: lst){
            tmp.emplace_back(x);
            for(char x:tmp)
                cout<<x<<' ';
            cout<<endl;
            dfs(dep+1);
            tmp.pop_back();
        }
    }
}
;
int32_t main(){
    init();
    dfs(0);
    return 0;
}