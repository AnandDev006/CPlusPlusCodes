// https://www.codechef.com/DI15R080/problems/MINMAXTF

#include <bits/stdc++.h>

using namespace std;

map < pair< pair< int, int>, int>, int> memeTable; // For Memoization, F : ( range, numSplits) -> soln

int solve( int arr[], int numSplits, int csum[], int start, int finish){
    
    int minim = INT_MAX;

    if( finish < start + numSplits ) // no valid splitting possible
        return INT_MAX;

    if( numSplits == 1 ){
        
        // split entire array into 1 piece = whole array itself
        // therefore sum of array elements

        minim = csum[finish-1] - csum[start] + arr[start];
        
        // Memoize
        memeTable[ make_pair( make_pair( start, finish), numSplits)] = minim;
        
        return csum[finish-1] - csum[start] + arr[start];
    }

    // If data already available in memo table, return that
    if( memeTable.find( make_pair( make_pair( start, finish), numSplits)) != memeTable.end() )
        return memeTable[ make_pair( make_pair( start, finish), numSplits)];

    for( int i = start ; i <= finish - (numSplits - 1) ; ++i ){
        // minimum among all solns of current state
        // curr state solns = max( sum(A[:i]), solve_subproblem(A[i:]) )
        minim = min( minim, max( csum[i] - csum[start] + arr[start], solve( arr, numSplits - 1, csum, i + 1, finish) ));
    }

    // Memoize
    memeTable[ make_pair( make_pair( start, finish), numSplits)] = minim;
    
    return minim;
}

int main(){
    
    int inputSize, numSplits;
    cin >> inputSize >> numSplits;

    int arr[inputSize];

    for( int i = 0 ; i < inputSize ; ++i )
        cin >> arr[i];

    int csum[inputSize] = {0};  // cumilative sum array

    csum[0] = arr[0];
    for( int i = 1 ; i < inputSize ; ++i )
        csum[i] = csum[i-1] + arr[i];

    int result = solve( arr, numSplits, csum, 0, inputSize);
    result = result == INT_MAX ? -1 : result;
    cout << result << endl;

    return 0;
}