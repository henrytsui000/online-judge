# include<bits/stdc++.h>
using namespace std ;

struct Date {
    int y ; // year
    int m ; // month
    int d ; // day
} ;

int Sum( Date d ) {
    int mlist[ 12 ] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } ;
    int cnt = 0 ;

    if ( d.y > 0 ) cnt += ( d.y * 365 ) + ( ( d.y - 1 ) / 4 + 1 ) - ( ( d.y - 1 ) / 100 ) + ( ( d.y - 1 ) / 400 ) ;

    for ( int i = 0 ; i < d.m - 1 ; i++ ) cnt += mlist[ i ] ;
    if ( d.m > 2 ) {
        if ( d.y % 4 == 0 && d.y % 100 != 0 ) cnt++ ;
        else if ( d.y % 4 == 0 && d.y % 400 == 0 ) cnt++ ;
    } // if

    cnt += d.d - 1 ;
    return cnt ;
} // Sum()

int Count( Date d1, Date d2 ) {
    int ans ;
    ans = Sum( d1 ) - Sum( d2 ) ;
    if( ans >= 0 ) return ans ;
    else return -ans ;
} // Count()

int main() {
    Date d1, d2 ; // date1, date2
    int ans ;

    while( cin >> d1.y >> d1.m >> d1.d >> d2.y >> d2.m >> d2.d ) {
        ans = Count( d1, d2 ) ;
        cout << ans << "\n" ;
    } // while
} // main()

