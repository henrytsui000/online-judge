#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i <(int)n;i++)
#define sz(a) ((int)a.size())
ifstream fin("4.in");
ofstream fout("4.out");
void solve(){
    int a, b;
    fin >> a >> b;
    fout << __gcd(a,b)<<endl;
}

int32_t main(){
    rep(i,10) {
        fout <<"case "<<i+1<<":\n";
        solve();
        fout << endl;
    }
    return 0;
}
