#include <iostream>
#include <vector>

using namespace std ;

void minHeapify( vector<pair<int,int>> &v , int size ){
    int left = 2*size + 1 ;
    int right = 2*size + 2 ;
    int smallest = size ;
    if( left < v.size() && v[left].first < v[smallest].first )
        smallest = left ;
    if( right < v.size() && v[right].first < v[smallest].first )
        smallest = right ;
    if( smallest != size ){
        swap( v[size] , v[smallest] ) ;
        minHeapify( v , smallest ) ;
    }
}

pair<int,int> extractMin( vector<pair<int,int>> &v ){
    pair<int,int> temp = v[0] ;
    swap( v[0] , v[ v.size() - 1 ] ) ;
    v.pop_back() ;
    minHeapify( v , 0 ) ;
    return temp ;
}

int main() {
    vector<pair<int,int>> O ;
    vector<pair<int,int>> N ;   // vector to hold k values and original index of them
    int size ,k ;
    pair<int,int> it ;
    cin >> size >> k ;

    for( int i = 0 ; i < size ; ++i )
        O.emplace_back( make_pair( rand() , i ) ) ;

    minHeapify( O , 0 ) ;

    N.emplace_back( make_pair( O[0].first , 0) ) ;

    for( int i = 0 ; i < k ; ++i ){
        it = extractMin( N ) ;
        if( 2*it.second + 1 < O.size() )
            N.emplace_back( make_pair( O[ 2*it.second + 1 ].first , 2*it.second + 1) ) ;
        if( 2*it.second + 2 < O.size() )
            N.emplace_back( make_pair( O[ 2*it.second + 2 ].first , 2*it.second + 2) );
        minHeapify( N , 0 ) ;
    }

    cout << endl << it.first << " : " << it.second + 1 << endl ;
    return 0;
}