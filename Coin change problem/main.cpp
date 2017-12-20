// https://www.youtube.com/watch?v=Y0ZqKpToTic

#include <bits/stdc++.h>

using namespace std;

int DP[1005][100005];
int coins[1005];
vector< int> output;
int N;
int Sum;

int main() {

    cin >> N >> Sum ;
    int i, j;

    for( i = 0 ; i < N ; ++i )
        cin >> coins[i];

    // Build
    for( i = 0 ; i < N ; ++i)
        DP[i][0] = 0;

    for( i = 0 ; i < N ; ++i){
        for( j = 1 ; j <= Sum ; ++j ){
            if( j < coins[i] )
                DP[i][j] = ( i == 0 ? INT32_MAX - Sum : DP[i-1][j] ) ;
            else
                DP[i][j] = min( ( i == 0 ? INT32_MAX - Sum : DP[i-1][j] ) , 1 + DP[i][j - coins[i] ] );
        }
    }

    // Retrace
    i = N-1; j = Sum;
    while( j > 0){
        if( DP[i][j] == DP[i-1][j] )
            --i;
        else{
            output.push_back( coins[i]);
            j = j - coins[i];
        }
    }

    int result =DP[N-1][Sum] ;
    cout << result << endl ;
    while( result-- )
        cout << output[result] << " ";

    return 0;
}