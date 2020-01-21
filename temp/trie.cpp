#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie()
#define endl '\n'
#define pb push_back
const int W=100;
struct Trie{
    vector<array<int,W>> ch;
    vector<int>cnt;
    Trie(){
        extand();
    }
    void extand(){
        ch.pb(array<int,W>());
        cnt.pb(0);
    }
    int getnext(int u,int c){
        if(ch[u][c]==0){
            extand();
            ch[u][c]=(int)ch.size()-1;
        }
    }
    void insert(const string &a){
        int u=0;
        for(char c:a){
            u=getnext(u,c-'a');
            ++cnt[u];
        }
    }
    void print(int u,string &a){
        rep(i,cnt[u])
            cout<<a<<endl;
        rep(i,W)if(ch[u][i]){
            a.pb(char('a'+i));
            print(ch[u][i],a);
            a.pop_back();
        }
    }
    void print(){
        string a;
        print(0,a);
    }

};
int main(){
    Trie trie;
    int n;
    cin>>n;
    while(n--){
        string a;cin>>a;
        trie.insert(a);
    }
    trie.print();
    return 0;
}