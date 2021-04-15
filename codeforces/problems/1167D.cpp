#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i <(int)n;i++)
#define endl '\n'
const int maxn = 2e5+5;
int arr[maxn];
void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    int deepest = 0, np = 0;
    rep(i, n){
        if(str[i] == '('){
            np++;
            arr[i] = np;
        }else{
            arr[i] = np;
            np--;
        }
        deepest = max(np, deepest);
    }
    rep(i,n)
        cout << (arr[i] > deepest/2?1:0);
    cout<<endl;
}

int main(){
    solve();
    return 0;
}