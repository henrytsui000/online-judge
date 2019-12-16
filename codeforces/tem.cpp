#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define cnas cout<<ans<<endl
#define pb push_back
#define eb emplace_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
const int maxn = 1000;
int arr[maxn];

struct node{
    node *lc,*rc;
    int l,c;
    int mx;
};

node *build(int l,int r){
    if(l==r-1)
        return new node{0,0,l,r,arr[l]};
    int mid=(l+r)<<1;
    return new node{

        
    }

}

int main(){


    return 0;
}
