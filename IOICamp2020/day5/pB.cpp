#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<ld,ld>;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define pb push_back
#define eb emplace_back
#define mp(a,b) make_pair(a,b)
#define cans cout<<ans<<endl
#define in cout<<"in lar"<<endl
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
    out<<'('<<P.F<<','<<P.S<<')';
    return out;
}

//}}}
const ll INF64=8000000000000000000LL;
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
const ld PI=acos(-1);
const ld eps=1e-9;
//const ll p=880301;
//const ll P=31;

ll mypow(ll a,ll b){
    ll res=1LL;
    while(b){
        if(b&1) res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

bool ok[65537][102][102];
pair<int,pii> from[65537];
int area[105];
int main(){
    IOS;
	int n,w,h,tx,ty,tz;
	cin>>n>>w>>h;
	if(w>100||h>100){
		cout<<"No\n";
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>area[i];
	}
	ok[0][0][0] = 1;
	int all = (1<<n);
	//cout<<all<<'\n';
	for(int i=0;i<all;i++){
		for(int j=0;j<n;j++){
			if(!(i&(1<<j)))continue;
			int tmp = i^(1<<j);
			//cout<<i<<" "<<j<<'\n';
			for(int k=1;k<=100;k++){
				if(area[j]%k == 0){
					//cout<<area[j]<<" "<<k<<'\n';
					int dx = area[j] / k ;
					int dy = area[j] / dx; 
					if(tmp==0){
						ok[i][dx][dy] = 1;
						from[i] = {j,{0,0}};
					}
					for(int l=h;l>=0;l--){
						if(ok[tmp][dx][l] && l + dy <=h){
							//cout<<tmp<<" "<<dx<<" "<<l<<'\n';
							ok[i][dx][l+dy] = 1;
							from[i] = {j,{dx,l}};
						} 
					}
					for(int k =w;k>=0;k--){
						if(ok[tmp][k][dy] && dx + k<=w){
							//cout<<tmp<<" "<<k<<" "<<dy<<'\n';
							ok[i][dx+k][dy] = 1;
							from[i] = {j,{k,dy}};
						}
					}
				}
			}
			
		}
	}
	if(ok[all-1][w][h]){
		cout<<"Yes\n";
		int x = all-1, y=w, z=h;
		while(x){
			//cout<<x<<'\n';
			int num = from[x].fi;
			//cout<<num<<'\n';
			//cout<<from[x][y][z].fi+1<<" "<<from[x][y][z].se.fi<<" "<<from[x][y][z].se.se<<'\n';
			if((x^num)==0){
				cout<<from[x].fi+1<<" "<<y<<" "<<z<<'\n';
			}
			else{
				int dx = y - from[x].se.fi;
				int dy;
				if(dx==0){
					dy = area[num] / y;
					dx = y; 
				}
				else{
					dy = z;
					dx = area[num] / z;
				}
				cout<<from[x].fi+1<<" "<<dx<<" "<<dy<<'\n';
			}
			
			tx = x^ (1<<from[x].fi) , ty = from[x].se.fi ,tz = from[x].se.se;
			x = tx, y=ty,z=tz;
			//cout<<x<<" "<<y<<" "<<z<<'\n';
		}
	}
	else{
		cout<<"No\n";
	}
}