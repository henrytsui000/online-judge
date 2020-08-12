#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int maxn = 1e5+5;

map<char , int> cn;
map<int ,char> nc;
int ar[8]={1,5,10,50,100,500,1000,5000};

void init(){
    cn['I']=1;nc[1]='I';
    cn['V']=5;nc[5]='V';
    cn['X']=10;nc[10]='X';
    cn['L']=50;nc[50]='L';
    cn['C']=100;nc[100]='C';
    cn['D']=500;nc[500]='D';
    cn['M']=1000;nc[1000]='M';
}

int tn(string str){
    int ret=0;
    rep(i,sz(str)){
        if(i&&cn[str[i]]>cn[str[i-1]])
            ret+=(cn[str[i]]-cn[str[i-1]]*2);
        else ret+=cn[str[i]];
    }
    return ret;
}

string nt(int num){
    string str;
    int nw=6;
    for(int i=3;i>=0;i--){
        int k=num/pow(10,i);
        if(k==9){
            str+=nc[pow(10,i)];
            str+=nc[pow(10,i)*10];
        }else if(k==4){
            str+=nc[pow(10,i)];
            str+=nc[pow(10,i)*5];
        }else{
            while(num>=pow(10,i)){
                if(num-ar[nw]>=0)
                    num-=ar[nw],str+=nc[ar[nw]];
                else nw--;
            }
        }
        num%=(int)pow(10,i);
    }
    return str;
}

int32_t main(){
    string a,b;
    init();
    while(cin>>a){
        if(a=="#") break;
        cin>>b;
        cout<<(tn(a)-tn(b)==0?"ZERO":nt(abs(tn(a)-tn(b))))<<endl;
    }
    return 0;
}