#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define IOS ios_basee::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define pb emplace_back
int arr[6];
vector<string> vec;
int32_t main(){
    int a,b,c;
    rep(i,26){
        for(int j=i+1;j<26;j++){
            rep(k,10){
                vec.pb((char)('a'+i)+(char)('a'+j)+(char)('0'+k));               
            }
        }
    }
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            for(int k=j+1;k<6;k++){
                memset(arr,0,sizeof(arr));
                arr[i]=-1,arr[j]=-2,arr[k]=-3;
            }
        }
    }
    return 0;
}