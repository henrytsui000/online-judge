#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i <(int)n;i++)
#define sz(a) ((int)a.size())
ifstream fin("2.in");
ofstream fout("2.out");
void solve(){
    int n;
    fin >> n;
    rep(i, (1<<n)){
        vector<int> vec;
        rep(j,n){
            if((i>>j)&1)
                vec.emplace_back(j+1);
        }
        fout <<"{";
        rep(j,sz(vec))
            fout << vec[j] << ",}"[sz(vec)-1 == j];
        if(sz(vec) == 0)fout <<"}";
        fout << endl;
    }
}

int32_t main(){
    rep(i,10) {
        fout <<"case "<<i+1<<":\n";
        solve();
        fout << endl;
    }
    return 0;
}
