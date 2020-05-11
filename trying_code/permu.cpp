#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)

const int maxn = 1e5+5;

int arr[maxn];//輸入陣列
int n;

int main(){
    int m;
    cin>>n>>m;//n是陣列長度 m是詢問次數 
    rep(i,n)// 輸入陣列數字
        cin>>arr[i];
    rep(i,m){// 總共有m次詢問嘛 所以迴圈跑m次 恩恩
        int a;cin>>a;
        if(lower_bound(arr,arr+n,a)-arr!=upper_bound(arr,arr+n,a)-arr-1)
            cout<<0<<endl;
        else cout<<lower_bound(arr,arr+n,a)-arr+1<<endl;
    }
    return 0;
}