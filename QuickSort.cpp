int partition( vector<int> &A , int Start , int End ){
    int pivot = A[End] , pIndex = Start ;

    for( int i = Start ; i < End ; ++i )
        if( A[i] <= pivot )
            swap( A[i] , A[pIndex++] ) ;
    swap( A[pIndex] , A[End] ) ;
    return pIndex ;
}

void quickRec( vector<int> &a , int start , int end ){

    if( start >= end )
        return ;
    int pIndex = partition ( a , start , end ) ;
    quickRec( a , start , pIndex - 1 ) ;
    quickRec( a , pIndex + 1 , end ) ;

}

void quickSort( vector<int> &x ){

    cout<< endl << "Quick sort : " ;

    clock_t tStart = clock() ;
    quickRec( x , 0 , n - 1 ) ;

    cout << (double)(clock() - tStart)/CLOCKS_PER_SEC ;

}