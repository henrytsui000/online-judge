#include<bits/stdc++.h>
using namespace std;

pair<int, string> pis[10];

void mysort(){
    for(int i = 0 ; i < 10; i ++ ){
        for(int j = i + 1; j < 10; j++ ){
            if(pis[i].first < pis[j].first)
                swap(pis[i], pis[j]);
        }
    }
}

void solve(){
    for(int i = 0 ; i < 10; i++){
        cin >> pis[i].second >> pis[i].first;
    }
    mysort();
    for(int i = 0; pis[i].first == pis[0].first; i++ ) {
        cout << pis[i].second << endl;
    }
}

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t;i++) {
        cout << "Case #" << i << ":\n"; 
        solve();
    }
    return 0;
}
