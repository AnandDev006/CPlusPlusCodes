#include <bits/stdc++.h>

using namespace std ;
int heapSize ;
int n ;
const int k = 100 ;

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

int partition( vector<int> &A , int Start , int End ){
    int pivot = A[End] , pIndex = Start ;

    for( int i = Start ; i < End ; ++i )
        if( A[i] < pivot )
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
    for( int i = heapSize / 2 ;  i >= 0 ; --i )
        max_heapify( A , i - 1 ) ;
}

void heapSort( vector<int> &A ){
    cout << endl << "Heap Sort : " ;

    clock_t tStart = clock() ;

    build_max_heap( A ) ;

    for( int i = heapSize - 1 ; i >= 0 ; --i ){
        swap( A[0] , A[i] ) ;
        heapSize -- ;
        max_heapify( A , 0 ) ;
    }

    heapSize = A.size() ;

    cout << (double)(clock() - tStart)/CLOCKS_PER_SEC ;
}

/*void printHeap( vector<int> A ){
    for( int i = 0 ; i < heapSize ; ++i )
        cout << ' ' << A[i] ;*/

void countingSort(vector<int> &A ){
    cout << endl << "Count Sort : " ;

    clock_t tStart = clock() ;

    vector<int> B( n , 0 ) , C ( k , 0 ) ;
    for( int i = 0 ; i < n ; ++i )
        C[ A[i] ] ++ ;
    int sum = n ;
    for( int i = k -1 ; i >= 0 ; --i )
        sum = C[i] = sum - C[i] ;
    for( int i = 0 ; i < n ; ++i )
        B[ C[ A[i] ]++ ] = A[i];
    A = B ;

    cout << (double)(clock() - tStart)/CLOCKS_PER_SEC ;
}

int main(){

    int t ;
    vector<int> array1 , array2 , array3 , array4 , array5 , array6 , array7 ;
    cin >> n;
    heapSize = n ;

    clock_t tStart = clock();

    for( int i = 0 ; i < n ; ++i ){
        t = rand() ;
        array1.push_back( t % k ) ;
        array2.push_back( t % k ) ;
        array3.push_back( t % k ) ;
        array4.push_back( t % k ) ;
        array5.push_back( t )     ;     // Quick sort not happy with multiple repeating values
        array6.push_back( t % k ) ;
        array7.push_back( t % k ) ;
    }

    cout << endl << "Assigning data : " << (double)(clock() - tStart)/CLOCKS_PER_SEC ;

    if( n < 10000){
	    selectionSort( array1 ) ;
	    bubbleSort( array2 ) ;
	    insertionSort( array3 ) ;
	}
    mergeSort( array4 ) ;
    quickSort( array5 ) ;
    heapSort( array6 ) ;
    countingSort( array7 ) ;

    return 0;
}