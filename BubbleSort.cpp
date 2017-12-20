void bubbleSort( vector<int> &a ){

    cout << endl << "Bubble sort : " ;

    clock_t tStart = clock() ;

    int flag ;
    for( int i = 0 ; i < n - 1 ; ++i){
        flag = 0 ;
        for( int j = 0 ; j < n - 1 - 1 ; ++j )
            if( a[j] > a[j+1] ){
                swap( a[j] , a[j+1] );
                flag = 1 ;
            }
        if( flag == 0 )
            break;
    }

    cout << (double)(clock() - tStart)/CLOCKS_PER_SEC ;

}