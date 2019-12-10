#include <iostream>
using namespace std;
#define M 10
const int N = 10001;
int n, wt[N], val[N], DP[N][M];

int main() {
while ( cin >> n ) {
for ( int i = 1; i <= n; ++i )
cin >> wt[i] >> val[i];

for ( int w = wt[1]; w <= M; ++w )
DP[1][w] = val[1];

for ( int i = 2; i <= n; ++i ){
for ( int j = 1; j <= M; ++j ) {
DP[i][j] = DP[i - 1][j];

if ( wt[i] <= j )
DP[i][j] = max ( DP[i][j], DP[i - 1][j - wt[i]] + val[i] );
cout<<DP[i][j]<<' ';
}
cout<<endl<<endl;
	
}
}

return 0;
}
