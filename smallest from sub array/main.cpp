#include <iostream>
#include <vector>

using namespace std ;

int findMin( vector<int>::iterator v , int size ){
    if( size == 1 )
        return *v ;
    int l = findMin( v , size/2 ) ;
    int r = findMin( v + size/2 , size/2 ) ;
    return min( l ,r ) ;
}

void print( vector<int>::iterator v , int size ) {
    cout << endl ;
    while( size > 0 ){
        cout << *v << " " ;
        --size ;
        ++v ;
    }
    cout << endl ;
}

int main() {
    vector<int> v ;
    int l , r , size ;
    cin >> size ;
    for( int i = 0 ; i < size ; ++i )
        v.push_back( rand() ) ;

    cin >> l >> r ;
    print( v.begin() , v.size() ) ;
    print( v.begin() + l - 1 , r - l + 1 ) ;
    int minimum = findMin( v.begin() + l - 1 , r - l + 1 ) ; // O( lg(N) )
    cout << endl << minimum ;
    return 0;
}