#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define F first
#define S second
using pii = pair<int,int>;
int main(){
    string str;
    IOS;
    while(cin>>str){
        str=str+'0';
        int n=str.size(),cnt=1;
        pair<char,int> ans;
        ans.F=str[0];
        for(int i=1;i<n;i++){
            if(str[i]!=str[i-1]){
                if(cnt>ans.S)
                    ans.S=cnt,ans.F=str[i-1];
                cnt=1;
            }else{
                cnt++;
            }
        }
        cout<<ans.F<<' '<<ans.S<<endl;
    }
    return 0;
}