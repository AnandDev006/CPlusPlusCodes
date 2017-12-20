#include <bits/stdc++.h>

using namespace std ;
int heapSize ;

void max_heapify( vector<int> &A , int i ){
    int left = 2 * i + 1 ;
    int right = 2 * i + 2 ;
    int largest = i ;
    if( left < heapSize && A[left] > A[largest] )
        largest = left ;
    if ( right < heapSize && A[right] > A[largest] )
        largest = right ;
    if( largest != i ){
        swap( A[i] , A[largest] ) ;
        max_heapify( A , largest ) ;
    }
}

void build_max_heap( vector<int> &A ){
    for( int i = heapSize / 2 ;  i > 0 ; --i )
        max_heapify( A , i - 1 ) ;
}

void heapSort( vector<int> &A ){
    cout << endl ;
    for( int i = heapSize - 1 ; i >= 0 ; --i ){
        swap( A[0] , A[i] ) ;
        heapSize -- ;
        max_heapify( A , 0 ) ;
    }
    heapSize = A.size() ;
}

void printHeap( vector<int> A ){
    for( int i = 0 ; i < heapSize ; ++i )
        cout << ' ' << A[i] ;
}
int main() {
    int t , temp ;
    cin >> t ;
    vector<int> X ;
    while( t-- ){
        cout << endl << "Enter array size : " ;
        cin >> heapSize ;
        for( int i = 0 ; i < heapSize ; ++i ) {
            cin >> temp ;
            X.push_back( temp );
        }
        build_max_heap( X ) ;
        cout << endl << "Max Heap : " ;
        printHeap( X ) ;
        heapSort( X ) ;
        cout << endl << "Heap Sort : " ;
        printHeap( X ) ;
    }
    return 0;
}