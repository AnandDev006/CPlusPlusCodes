#include <bits/stdc++.h>

using namespace std;

int DP[1006][1006];
int input[1005][1005];
int row, col;

int main() {
    cin >> row >> col;
    int i, j;
    for( i = 0 ; i < row ; ++i )
        for( j = 0 ; j < col ; ++j )
            cin >> input[i][j] ;

    // Build
    // DP[i][j] will hold size of largest square having bottom right corner at i,j
    int r = 0, c = 0;
    for( i = 0 ; i <= row ; ++i )
        DP[i][0] = 0;
    for( j = 0 ; j <= col ; ++j )
        DP[0][j] = 0;
    for( i = 1 ; i <= row ; ++i ){
        for( j = 1 ; j <= col ; ++j ){
            if( input[i-1][j-1] == 0 )
                DP[i][j] = 0 ;
            else{
                DP[i][j] = 1 + min( DP[i-1][j-1], min( DP[i-1][j], DP[i][j-1]));
                if( DP[i][j] > DP[r][c] ){
                    r = i;
                    c = j;
                }
                /*
                 * the bottom right corner being added will only be valid if we add it to a square
                 * which is the smallest among the 3 bottom right corners surrounding it
                 * hence we take minimum among the 3 possible squares.
                 */
            }
        }
    }
    int result = DP[r][c];
    cout << result*result << endl << r-1 << " " << c-1 << endl ;
    return 0;
}