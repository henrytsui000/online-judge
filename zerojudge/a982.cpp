#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
const int maxn = 105;
const int inf = 0x3f3f3f3f;
int arr[maxn][maxn];
int dic[4][2]={1,0,-1,0,0,1,0,-1};
void gogo(int x,int y){
	rep(i,4)
		if(arr[x+dic[i][0]][y+dic[i][1]]!=-1&&arr[x+dic[i][0]][y+dic[i][1]]>arr[x][y]+1){
			arr[x+dic[i][0]][y+dic[i][1]]=arr[x][y]+1;
			gogo(x+dic[i][0],y+dic[i][1]);
		}
}
int32_t main(){
	IOS;
	int n;
	cin>>n;
	memset(arr,inf,sizeof(arr));
	rep(i,n)
		rep(j,n){
			char c; cin>>c;
			if(c=='#')
				arr[i][j]=-1;
		}
	arr[1][1]=1;
	gogo(1,1);
	if(arr[n-2][n-2]==inf) cout<<"No solution!"<<endl;
	else cout<<arr[n-2][n-2]<<endl;
	return 0;
}