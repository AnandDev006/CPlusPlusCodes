void selectionSort( vector<int> &a ){

    cout << endl << "Selection sort : " ;

    clock_t tStart = clock() ;

    int min ;
    for( int i = 0 ; i < n - 1 ; ++i){
        min = i ;
        for( int j = i + 1 ; j < n ; ++j )
            if( a[j] < a[min] )
                min = j ;
        int temp = a[i] ;
        a[i] = a[min] ;
        a[min] = temp ;
    }

    cout << (double)(clock() - tStart)/CLOCKS_PER_SEC ;

}