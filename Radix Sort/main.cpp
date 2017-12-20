#include <iostream>
#include <vector>

using namespace std ;

int n , k ;

bool countingSort( vector<int> &A , int p ) {
    vector<int> B ( n , 0 ), C( k , 0 ) ;
    bool sort = false ;
    for (int i = 0; i < n; ++i){                    // Use 256 only if integers are large , ie: >= 256 ( > 1 byte )
        if( ( ( A[i] / p ) % 10 ) != 0 )
            sort = true ;
        C[ ( A[i] / p ) % 10 ]++ ;
    }
    int sum = n;
    for ( int i = k - 1 ; i >= 0 ; --i )
        C[i] = sum = sum - C[i] ;
    for ( int i = 0 ; i < n ; ++i )
        B[ C [ ( A[i] / p ) % 10 ]++ ] = A[i] ;
    A = B ;
    return sort ;
}

void radixSort( vector<int> &A ){
    int p = 10 ;
    while( countingSort( A , p ) )
        p *= p ;
}

int main() {
    cin >> n >> k ;
    vector < int > A ( n , 0 ) ;
    for( int i = 0 ; i < n ; ++i )
        A[i] = rand() % k ;
    for( int i = 0 ; i < n ; ++i )
        cout << A[i] << ' ' ;
    cout << endl ;

    radixSort( A ) ;

    for( int i = 0 ; i < n ; ++i )
        cout << A[i] << ' ' ;
    return 0;
}