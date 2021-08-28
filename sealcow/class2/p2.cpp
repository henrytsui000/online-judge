#include<bits/stdc++.h>
using namespace std;

map<string, string> mp;

void init(){
    mp[".-"]="A",mp["-..."]="B",mp["-.-."]="C",mp["-.."]="D",mp["."]="E",mp["..-."]="F",mp["--."]="G",mp["...."]="H",mp[".."]="I",mp[".---"]="J",mp["-.-"]="K",mp[".-.."]="L",mp["--"]="M",mp["-."]="N",mp["---"]="O",mp[".--."]="P",mp["--.-"]="Q",mp[".-."]="R",mp["..."]="S",mp["-"]="T",mp["..-"]="U",mp["...-"]="V",mp[".--"]="W",mp["-..-"]="X",mp["-.--"]="Y",mp["--.."]="Z";
}

void solve(){
    string str;
    getline(cin, str);
    str+=" ";
    string tmp;
    for(int i = 0 ; i < str.size();i++){
        if(str[i] != ' ')
            tmp+=str[i];
        else {
            cout << mp[tmp];
            tmp="";
        }
    }
    cout << endl;
}

int main(){
    init();
    int t;
    cin >> t;
    char c = getchar();
    while(t--){
        solve();
    }
    return 0;
}
