#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const unsigned long long int SIZE = 20000001;
bool prime[SIZE];
vector <unsigned long long int> table;

int main() {
memset ( prime, true, SIZE );
unsigned long long int i, j, n, ans;

for ( i = 2; i < SIZE; ++i )
if ( prime[i] ) {
table.push_back ( i );

for ( j = 2 * i; j < SIZE; j += i )
prime[j] = false;
}

while ( cin >> n ) {
ans = 0;

for ( i = 0; i < table.size() && n > 1; ++i )
while ( 0 == n % table.at ( i ) ) {
ans += table.at ( i );
n /= table.at ( i );
}

cout << ( ( 1 == n ) ? ans : ans + n ) << endl;
}

}