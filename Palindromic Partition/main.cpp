#include <bits/stdc++.h>

using namespace std;

int DP[1005][1005];
int input[1005];
int N;

bool isPalindrome( int i, int j){
    for( ; i <= j ; )
        if( input[i++] != input[j--] )
            return false;
    return true;
}

int main() {
    cin >> N;
    int i, j, m, l;
    for( i = 0 ; i < N ; ++i )
        cin >> input[i];

    //Build
    l = 1;
    for( m = 0 ; m < N ; ++m )
        DP[m][m] = 0;
    for( l = 2 ; l <= N ; ++l ){
        for( i = 0 ; i < N ; ++i ){
            j = i + l - 1;
            if( isPalindrome( i, j) )
                DP[i][j] = 0;
            else{
                DP[i][j] = INT32_MAX;
                for( m = i ; m < j ; ++m )
                    DP[i][j] = min( DP[i][j], 1 + DP[i][m] + DP[m+1][j] ) ;
            }
        }
    }
    int result = DP[0][N-1];
    cout << result << endl ;
    // Retrace
    i = 1; j = 0;
    for( m = 0 ; m < N-1 ; ++m )
        if( DP[0][m] + DP[m+1][N-1] + 1 == result )
            cout << m << " " ;

    return 0;
}