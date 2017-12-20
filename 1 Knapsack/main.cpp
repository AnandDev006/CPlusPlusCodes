#include <bits/stdc++.h>

using namespace std;

int DP[2001][2001];
pair< int, int> items[2001]; // wt , value
int N;
int S;

int knapsack(){
    int row = N+1;
    int col = S+1;
    for( int i = 0 ; i < row ; ++i){
        for( int j = 0 ; j < col ; ++j){
            if( i == 0 || j == 0)
                DP[i][j] = 0;
            else if( items[i-1].first > j )
                DP[i][j] = DP[i-1][j];
            else
                DP[i][j] = max( items[i-1].second + DP[ i - 1 ][ j - items[i-1].first ], DP[i-1][j] );
        }
    }
    return DP[row-1][col-1];
}

int main() {
    int T;
    cin >> T;
    while( T--){
        cin >> S >> N ;
        for( int i = 0 ; i < N ; ++i )
            cin >> items[i].first >> items[i].second;
        cout << knapsack() << endl ;
    }
    return 0;
}