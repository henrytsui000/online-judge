#include<bits/stdc++.h>
using namespace std;

int calculus(int n){
    int tmp = 0;
    while(n){
        tmp+=(n%10)*(n%10);
        n/=10;
    }
    return tmp;
}

void solve() {
    int n;
    cin >> n;
    cout << n;
    set<int> s;
    while( n != 1 && !s.count(n)){
        s.insert(n);
        n = calculus(n);
    }
    if(n == 1)
        cout << " is a Happy number."<<endl;
    else 
        cout << " is an Unhappy number."<<endl;
}

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout <<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
