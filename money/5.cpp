#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i <(int)n;i++)
#define sz(a) ((int)a.size())
ifstream fin("5.in");
ofstream fout("5.out");
vector<int> ans;
void gogo(int n, int mi){
    if(n <= 0){
        for(int x:ans)
            fout << x<<' ';
        fout <<endl;
        return;
    }else if(n < 0)return;
    for(int i = mi; i > 0; i--) if(n - i >= 0){ 
        ans.emplace_back(i);
        gogo(n-i, i);
        ans.pop_back();
    }
}

void solve(){
    int n;
    fin >> n;
    gogo(n, n);
}

int32_t main(){
    rep(i,10) {
        fout <<"case "<<i+1<<":\n";
        solve();
        fout << endl;
    }
    return 0;
}
