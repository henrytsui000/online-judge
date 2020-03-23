#include<bits/stdc++.h>
using namespace std;
int main(){
    double n, k,LOG;
    int digit;
    while(cin>>n>>k){
        LOG=0;
        k=min(k,n-k);
        for(int i=1;i<=k;i++)
            LOG+=log10((n-i+1)/i);
        digit=floor(LOG);
        cout<<digit+1<<endl;
    }
    return 0;
}