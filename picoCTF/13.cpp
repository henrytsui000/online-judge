#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
int main(){
    string str;
    cin>>str;
    int key=str[0]-'p';
    rep(i,str.size()){
        if(str[i]=='_'){
            cout<<"_";
            continue;
        }
        int c=str[i]-key;
        if(c>'z')
            c-=26;
        cout<<(char)c;

    }
    cout<<endl;
    return 0;
}