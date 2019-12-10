#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<((int)n);i++)
#define cans cout<<ans<<endl
const ll MOD=ll(1e9+7);
int main(){
	ll a,j=2,cnt=0,ans=0;
	cin>>a;
	rep(i,a-cnt+1)
		ans=(ans+=(a%(i)));
	rep(i,j-1)
		ans=(ans+(a%i)*(a/i-a/(i+1))+(a/i-a/(i+1))*((a/i-a/(i+1)-1)/2*i));
	cans;
	return 0;
}
