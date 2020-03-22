#include <iostream>
using namespace std;

int main() {
string input;

while ( cin >> input ) {
int ASCII[256] = {0}, oddCnt = 0;

for ( int i = 0; i < input.length(); ++i )
if ( isalpha ( input[i] ) ) {
input[i] = toupper ( input[i] );
++ASCII[input[i]];
}

for ( int i = 0; i < 256; ++i )
if ( ASCII[i] % 2 )
++oddCnt;

cout << ( oddCnt <= 1 ? "yes !" : "no..." ) << endl;
}

return 0;
}