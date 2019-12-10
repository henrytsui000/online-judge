#include<bits/stdc++.h>
using namespace std;
#define maxn 10005
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
bool sieve[maxn];
vector<int> vec;
void liner_prime(){
    for(int i=2;i<maxn;i++){
        if(!sieve[i])
            vec.emplace_back(i);
        for(int j=0;vec[j]*i<maxn;j++){
            sieve[i*vec[j]]=1;
            if(i%vec[j]==0)
                break;
        }
    }
}
int main(){
    IOS;
    liner_prime();
    int n;cin>>n;
    cout<<(sieve[n] == 0 ?"yes":"no")<<endl;
    return 0;
}