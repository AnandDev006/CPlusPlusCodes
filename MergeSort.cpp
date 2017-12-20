void merge ( vector<int> &L , vector<int> &R , vector<int> &A ){
    int nL = L.size() ;
    int nR = R.size() ;
    int i = 0 , j = 0 , k = 0 ;
    while( j < nL && k < nR )
        if( L[j] <= R[k] )
            A[i++] = L[j++] ;
        else
            A[i++] = R[k++] ;
    while( j < nL )
        A[i++] = L[j++] ;
    while( k < nR )
        A[i++] = R[k++] ;
}

void mergeRec( vector<int> &a ){
    int N = a.size();
    if( N < 2 )
        return;
    int mid = N / 2 ;
    vector<int> left ( mid ) ;
    vector<int> right ( N - mid );
    for( int i = 0 ; i < mid ; ++i )
        left[i] = a[i] ;
    for( int j = mid ; j < N ; ++j )
        right[j - mid] = a[j] ;
    mergeRec( left ) ;
    mergeRec( right ) ;
    merge( left, right , a ) ;
}

void mergeSort( vector<int> &x ){

    cout << endl << "Merge sort : " ;

    clock_t tStart = clock() ;

    mergeRec( x ) ;

    cout << (double)(clock() - tStart)/CLOCKS_PER_SEC ;

}