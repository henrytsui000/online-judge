#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define endl '\n'
#define pb push_back
#define ep emplace_pack
#define cans cout<<ans<<endl
#define debug cout<<"debug"<<endl;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define last_bit(x) ((x)&(-x))
using ll = long long;
using pii = pair<int,int>;
#define MAXN 1000
int arr[MAXN];

struct dis{
    int arr[MAXN];
    void init(int r){
        rep(i,r)
            arr[i]=r;
    }
    bool same(int a,int b){
        return find(a)==find(b);
    }
    int find(int a){
        if(a==arr[a])   return a;
        return arr[a]=find(a);
    }
    void Union(int a,int b){
        arr[find(a)]=arr[b];
    }
}d;

void diz(){
    set<int> s;
    map<int,int> m;
    rep(i,MAXN)
        s.insert(arr[i]);
    int rk=1;
    for(auto x:s)m[x]=rk++;
    rep(i,MAXN)
        arr[i]=m[arr[i]];
}

ll mypow(int a,int b){
    ll res=1;
    while(b){
        if(b&1)
            a*=res;
        a*=a;
        b>>=1;
    }
    return res;
}

bool sieve[MAXN];
vector<int> prime;
void find_prime(){
    for(int i=2;i<MAXN;i++){
        if(!sieve[i])
            prime.pb(i);
        for(int j=0;prime[j]*i<MAXN;j++){
            sieve[i*prime[j]]=true;
            if(i%prime[j]==0)
                break;
        }
    }
}

vector<int> vec;
void q(int a){
    int r=0;
    while(a){
        if(a%prime[r]==0){
            vec.pb(prime[r]);
            while(a%prime[r]!=0)
                a*=prime[r];
        }
        r++;
    }
}

void martix_fastpow(){

}

int main(){



    return 0;
}