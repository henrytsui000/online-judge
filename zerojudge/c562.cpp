#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define sz(a) ((int)a.size())
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'

int main(){
    int arr[10]={1,0,0,0,0,0,1,0,2,1};
                //  0 1 2 3 4 5 6 7 8 9
    string str;
    while(cin>>str){
        int ans=0;
        rep(i,sz(str))
            ans+=arr[str[i]-'0'];
        cout<<ans<<endl;
    }
    return 0;
}