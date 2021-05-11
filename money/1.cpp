#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i <(int)n;i++)
ifstream fin("1.in");
ofstream fout("1.out");
vector<int> ans;
int n, m;
void gogo(int siz, int nw){
    if(ans.size() == siz){
        for(int x: ans) fout << x;
        fout <<endl;
        return;
    }
    for(int i = nw + 1; i <= n; i++){
        ans.emplace_back(i);
        gogo(siz, i);
        ans.pop_back();
    }
}
void solve(){
    fin >> n >> m;
    gogo(m, 0);
}

int32_t main(){
    rep(i,10) {
        fout <<"case "<<i+1<<":\n";
        solve();
        fout << endl;
    }
    return 0;
}
