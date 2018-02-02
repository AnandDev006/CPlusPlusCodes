// https://www.codechef.com/DI15R080/problems/MINMAXTF

#include <bits/stdc++.h>

using namespace std;

map < pair< pair< int, int>, int>, int> range;

int solve( int arr[], int numSplits, int csum[], int start, int finish){
    
    int minim = INT_MAX;

    if( finish < start + numSplits )
        return INT_MAX;

    if( numSplits == 1 ){
        minim = csum[finish-1] - csum[start] + arr[start];
        range[ make_pair( make_pair( start, finish), numSplits)] = minim;
        return csum[finish-1] - csum[start] + arr[start];
    }

    if( range.find( make_pair( make_pair( start, finish), numSplits)) != range.end() )
        return range[ make_pair( make_pair( start, finish), numSplits)];

    for( int i = start ; i <= finish - (numSplits - 1) ; ++i ){
        minim = min( minim, max( csum[i] - csum[start] + arr[start], solve( arr, numSplits - 1, csum, i + 1, finish) ));
    }
    range[ make_pair( make_pair( start, finish), numSplits)] = minim;
    return minim;
}

int main(){
    
    int inputSize;
    cin >> inputSize;

    int arr[inputSize];

    for( int i = 0 ; i < inputSize ; ++i )
        cin >> arr[i];

    int csum[inputSize] = {0};

    csum[0] = arr[0];
    for( int i = 1 ; i < inputSize ; ++i )
        csum[i] = csum[i-1] + arr[i];

    int numSplits;
    cin >> numSplits;

    int result = solve( arr, numSplits, csum, 0, inputSize);
    result = result == INT_MAX ? -1 : result;
    cout << result << endl;

    return 0;
}