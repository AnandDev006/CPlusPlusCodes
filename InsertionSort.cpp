void insertionSort( vector<int> &a ){

    cout << endl << "Insertion sort : " ;

    clock_t tStart = clock() ;
    int value , hole ;
    for( int i = 1 ; i < n - 1 ; ++i){
        value = a[i] ;
        hole = i ;
        while( hole > 0 && a[hole-1] > value )
            a[hole--] = a[hole - 1] ;
        a[hole] = value ;
    }

    cout << (double)(clock() - tStart)/CLOCKS_PER_SEC ;

}