#include<bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int arr[maxn];

void solve(int n) {
    while(true){
        stack<int> s;
        int top = n;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            if(a == 0)
                return;
            s.push(a);
        }
        stack<int> station;
        while(top){
            if(s.size() && top == s.top()){
                top--;
                s.pop();
            } else if(station.size() && top == station.top()){
                top--;
                station.pop();
            } else if(s.size()){
                station.push(s.top());
                s.pop();
            } else {
                break;
            }
        } 
        cout << (top?"No":"Yes") << endl;
    }
}

int main(){
    int n;
    while(cin >> n && n){
        solve(n);
    }
    return 0;
}
