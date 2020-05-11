#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
const int maxn = 2*1e5+5;
int arr[maxn];

const int N = 20000000;
bool sieve[N];
 int n;
void linear_sieve()
{
    vector<int> prime;
    for (int i=2; i<n; i++){
        if (!sieve[i]) prime.push_back(i);
        cout<<i<<":";
        for (int j=0; i*prime[j]<n; j++){
            cout<<i*prime[j]<<' ';
            sieve[i*prime[j]] = true;
            if (i % prime[j] == 0) {
                cout<<endl;
                cout<<"B:"<<i<<' '<<prime[j]<<endl;
                break;
            }
        }
        cout<<endl;
    }
}
int32_t main(){
    // int n;
    cin>>n;
    linear_sieve();
    return 0;
}