#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
const int maxn = 1e5;
/*
用strust node模擬二元樹
l,r,hav分別紀錄 左，右節點以下的總重量 以及 該節點以下的重量
init 函式 用遞迴初始化二元樹
gogo是按照題目把貨物下放
**因為個節點沒有按照順序 不能先開指標二元樹 所以用陣列模擬**
*/
struct node{
    int lc,rc;
    int l,r;
    int hav;
};

node nd[maxn];
int n,m;

void gogo(int now,int weight){
    nd[now].hav+=weight;
    if(now>=n){
        cout<<now<<' ';
    }else if(nd[now].l<=nd[now].r){
        nd[now].l+=weight;
        gogo(nd[now].lc,weight);
    }else{
        nd[now].r+=weight;
        gogo(nd[now].rc,weight);
    }
}

void init(int now){
    if(now<n){
        init(nd[now].lc);
        init(nd[now].rc);
        nd[now].l=nd[nd[now].lc].hav;
        nd[now].r=nd[nd[now].rc].hav;
        nd[now].hav=nd[now].l+nd[now].r;
    }
}


int main(){
    cin>>n>>m;
    rep(i,n)
        cin>>nd[n+i].hav;
    int w[105];

    rep(i,m)
        cin>>w[i];
        
    rep(i,n-1){
        int p,s,t;
        cin>>p>>s>>t;
        nd[p].lc=s;
        nd[p].rc=t;
    }
    init(1);

    rep(i,m)
        gogo(1,w[i]);
    cout<<endl;
    return 0;
}
/*
4 5
0 0 0 0
5 4 3 2 1
1 2 3
2 4 5
3 6 7
*/