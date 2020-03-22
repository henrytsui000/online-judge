#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'


int main(){
	IOS;
	#define int ll
	int x,y;
	int a,b,c,d;
	cin>>x>>y>>a>>b>>c>>d;
	int ansx=0,ansy=0,ans;
	if(x>a&&x<c)
		if(y>b&&y<d)
			cout<<0<<endl;
		else cout<<min(abs(b-y),abs(y-d));
	if(y>b&&y<d)
		cout<<min(abs(x-a),abs(x-c));
	else cout<<min(abs(x-a),abs(x-c))+min(abs(b-y),abs(y-d));
	cout<<endl;
	return 0;
}

