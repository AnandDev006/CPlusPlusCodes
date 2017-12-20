#include <bits/stdc++.h>

using namespace std;

int DP[1005][1005];
int input[1005];
int N;

int main() {
    cin >> N;
    int i, j, l;

    for( i = 0 ; i < N ; ++i )
        cin >> input[i];

    // Build
    for( i = 0 ; i < N ; ++i ) // when L = 1
        DP[i][i] = 1;
    for( l = 2 ; l <= N ; ++l ){
        for( i = 0 ; i <= N - l ; ++i ){
            j = i + l - 1 ;
            if( input[i] == input[j] )
                if( l == 2 )
                    DP[i][j] = 2;
                else
                    DP[i][j] = 2 + DP[i+1][j-1];
            else
                DP[i][j] = max( DP[i][j-1], DP[i+1][j]);
        }
    }
    int result = DP[0][N-1];
    cout << endl << result << endl;
    // retrace
    i = 0 ; j = N-1;
    set< int> output;
    while( i <= j ){
        if( input[i] == input[j] ) {
            output.insert( i);
            output.insert( j);
            ++i;
            --j;
        }
        else if( DP[i][j] == DP[i][j-1] )
            --j;
        else if( DP[i][j] == DP[i+1][j] )
            ++i;
    }
    for( auto x : output )
        cout << input[x] << " ";
    
    return 0;
}