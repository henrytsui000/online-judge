#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i <(int)n ;i ++)
#define endl '\n'
const int maxn = 2e5+5;
using pii = pair<int,int>;
#define F first
#define S second
vector<pii> vec;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int time_in, time_out;
        cin >> time_in >> time_out;
        vec.emplace_back(make_pair(time_in, 1));
        vec.emplace_back(make_pair(time_out, -1));
    }
    sort(vec.begin(), vec.end());
    int mx = 0, now_people = 0;
    for(pii x: vec){
        now_people+=x.second;
        mx = max(mx, now_people);
    }
    cout << mx << endl;
    return 0;
}
