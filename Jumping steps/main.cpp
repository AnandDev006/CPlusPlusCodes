#include<bits/stdc++.h>

using namespace std;

unordered_set<int> steps ;
unordered_map< int, int> memoTable;

int fun( int n){
    
    if( n < 0 )
        return 0;
    else if( n == 0 )
        return 1;
    
    if( memoTable.find(n) != memoTable.end() ){
        return memoTable[n];
    }
    
    for( auto step : steps){
        memoTable[n] += fun( n - step);
    }

    return memoTable[n];

}

int main(){

    int N = 5;
    steps = {1,3,5};
    cout << fun(N) << endl;

    cin.get();
    return 0;
}