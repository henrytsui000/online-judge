#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define eb emplace_back
/*
利用vector容器紀錄機器人應出的拳
再跟人比較
若有輸贏則結束
否則直到最後
*/
int main(){
    int f;cin>>f;
    vector<int> rob;
    rob.eb(f);
    int n;cin>>n;
    int arr[n];
    rep(i,n)
        cin>>arr[i];
    rep(i,n){
        if(i==0){
            rob.eb(arr[0]);
        }else{
            if(arr[i-1]==arr[i]){
                if(arr[i]==0)
                    rob.eb(5);
                else if(arr[i]==2)
                    rob.eb(0);
                else rob.eb(2);
            }else{
                rob.eb(arr[i]);
            }
        }
    }
    rep(i,n){
        cout<<rob[i]<<' ';
        if(arr[i]!=rob[i]){
            if(arr[i]==2){
                if(rob[i]==0)
                    cout<<": Won at round "<<i+1<<endl;
                else cout<<": Lost at round "<<i+1<<endl;
            }else if(arr[i]==5){
                if(rob[i]==2)
                    cout<<": Won at round "<<i+1<<endl;
                else cout<<": Lost at round "<<i+1<<endl;
            }else{
                if(rob[i]==5)
                    cout<<": Won at round "<<i+1<<endl;
                else cout<<": Lost at round "<<i+1<<endl;
            }
            cout<<endl;
            return 0;
        }
    }
    cout<<": Drew at round "<<n<<endl;
    
    return 0;
}