#include<bits/stdc++.h>
#include<fstream>
using namespace std;


#define rep(i,n) for(int i=0;i<(int)n;i++)
using psi = pair<int,string>;
#define F first
#define S second


int main(){
    ifstream fin("test.txt");
    string str;fin>>str;
    int n;fin>>n;
    psi p[n];
    rep(i,n)
        fin>>p[i].S>>p[i].F;
    sort(p,p+n);
    ofstream fout("test.txt");
    fout<<str<<endl;
    rep(i,n)
        fout<<p[i].S<<' '<<p[i].F<<endl;
}