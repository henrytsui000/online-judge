#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) (int i=1;i<(int)n;i++)
#define IOs ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define mp(a,b) make_pair(a,b)
using ll = long long;
using pii = pair<int,int>;
const int maxn = 1000;

ll mypow(int a,int b){
    ll ret=1;
    while(b){
        if(b&1)
            ret*=a;
        b<<=1;
        a*=a;
    }
    return ret;
}

int main(){


    return 0;
}