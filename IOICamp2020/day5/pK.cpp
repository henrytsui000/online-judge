#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(0),cin.tie(0);
#define pii pair<ll,ll>
using namespace std;
int cnt = 0;
vector<pii> E[3005];
bool used[3000050];
vector<int> order;
void dfs(int x){
	//cout<<x<<'\n';
	for(auto i:E[x]){
		if(used[i.se])continue;
		used[i.se] = 1;
		dfs(i.fi);
	}
	order.pb(x);
}
int main(){
	IOS; 
	int n;
	cin>>n;
	if(n>2&&n%2==0){
		cout<<-1<<'\n';
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cnt++;
			E[i].pb({j,cnt});
			E[j].pb({i,cnt}); 
		}
	}	
	dfs(1);
	int now=0;
	//cout<<order.size()<<'\n';
	for(int i=1;i<=n-1;i++){
		for(int x=now;now<=i+x;now++){
			cout<<order[now]<<" \n"[now==i+x];
			if(now==i+x)break;
		}
	}

}
/*
5
1 5
5 4 3
3 5 2 4
4 1 3 2 1
6
-1
*/