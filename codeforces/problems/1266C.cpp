#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
const int maxn = 505;
int arr[maxn][maxn];
int32_t main(){
    int a,b;
    cin>>a>>b;
    bool key = false;
    if(a==1&&a*b!=1){
        rep(i,b)
            cout<<i+2<<' ';
        cout<<endl;
    }else if(a*b!=1){
        rep(i,b+1){
            arr[0][i]=i+2;
        }
        rep(i,a+1){
            arr[i][0]=i+b;
        }
        arr[0][1]=1;
        arr[1][0]=2,arr[2][0]=3;
        rep1(i,a)
            rep1(j,b)
                arr[i][j]=arr[0][j]*arr[i][0];
        rep1(i,a){
            rep1(j,b){
                    cout<<arr[i][j]<<' ';
            }
            cout<<endl;
        }
    }else{
        cout<<0<<endl;
    }
    return 0;
}
