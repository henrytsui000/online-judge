#include<bits/stdc++.h>
#define all(n) (n).begin(),(n).end()
#define IOS ios::sync_with_stdio(0),cin.tie(0);
#define ll long long
using namespace std;
ll n,m,w;
string e1,e2;
ll dp[305][305][305];
ll ans[305];
ll c[26];
ll mc=1e9+10;
int main(){
	IOS;
	cin>>n>>m>>w;
	//assert(n>=1&&m>=1);
	cin>>e1>>e2;
	for(int i=0;i<26;i++){
		cin>>c[i];
		mc = min(mc,c[i]);
	}
	mc*=2;
	e1 = "$" + e1;
	e2 = "%" + e2;
	memset(dp,0x3f,sizeof(dp));
	memset(ans,0x3f,sizeof(ans));
	int siz1 = e1.size()-1,siz2 = e2.size()-1;
	dp[0][0][0] = 0;
	ans[0] = 0;
	for(int i=0;i<=siz1;i++){
		for(int j=0;j<=siz2;j++){
			dp[i][j][0] = 0;
			for(int k=1;k<=max(i,j);k++){
				if(!i){
					dp[i][j][k] = min(dp[i][j-1][k],dp[i][j-1][k-1]+c[e2[j]-'a']);
					ans[k] = min(ans[k],dp[i][j][k]);
					continue;
				}
				if(!j){
					dp[i][j][k] = min(dp[i-1][j][k],dp[i-1][j][k-1]+c[e1[i]-'a']);
					ans[k] = min(ans[k],dp[i][j][k]);
					continue;
				}
				if(e1[i]==e2[j]) dp[i][j][k] = dp[i-1][j-1][k-1];
				else dp[i][j][k] = min({dp[i-1][j-1][k-1]+min(c[e1[i]-'a'],c[e2[j]-'a']) , dp[i][j-1][k] , dp[i-1][j][k],dp[i][j-1][k-1]+c[e2[j]-'a'],dp[i-1][j][k-1]+c[e1[i]-'a']});
				ans[k] = min(ans[k],dp[i][j][k]);
				//cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<'\n';
			}
		}
	}	
	ll x = 0;
    assert(mc<400000000);
	//cout<<w<<" "<<mc<<" "<<'\n';
	for(int i=0;i<=max(siz1,siz2);i++){
		//cout<<ans[i]<<'\n';
		if(ans[i]>w) continue;
		x = max(x,i + (w-ans[i])/mc);
		//cout<<i<<" "<<x<<'\n';
	}
	cout<<x<<'\n';
}