#include <iostream>
#include <vector>

using namespace std ;

int main() {
    int n , k ;
    cin >> n >> k ;
    vector < int > A ( n , 0 ) , B ( n , 0 ) , C( k , 0 ) ;
    for( int i = 0 ; i < n ; ++i )
        A[i] = rand() % k ;
    for( int i = 0 ; i < n ; ++i )
        cout << A[i] << ' ' ;
    cout << endl ;
    for( int i = 0 ; i < n ; ++i )
        C[ A[i] ] ++ ;
    int sum = n ;
    for( int i = k -1 ; i >= 0 ; --i )
        sum = C[i] = sum - C[i] ;
    for( int i = 0 ; i < n ; ++i )
        B[ C[ A[i] ]++ ] = A[i];
    for( int i = 0 ; i < n ; ++i )
        cout << B[i] << ' ' ;
    return 0;
}