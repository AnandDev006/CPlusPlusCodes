#include <bits/stdc++.h>

using namespace std;

int DP[1005][1005];
string s1;
string s2;

int main() {
    cin >> s1 >> s2 ;
    int i, j;
    int row, col, maxim = INT32_MIN;

    // Build
    for( i = 0 ; i <= s1.length() ; ++i )
        DP[i][0] = 0 ;
    for( j = 0 ; j <= s2.length() ; ++j )
        DP[0][j] = 0 ;
    for(  i = 1 ; i <= s1.length() ; ++i ){
        for( j = 1 ; j <= s2.length() ; ++j ){
            if( s1[i-1] == s2[j-1] ){
                DP[i][j] = 1 + DP[i-1][j-1];
                if( DP[i][j] > maxim ){
                    maxim = DP[i][j];
                    row = i;
                    col = j;
                }
            }
        }
    }
    cout << maxim << endl ;
    // Retrace
    i = row; j = col;
    while( DP[i--][j--] != 0 )
        cout << s1[i] << " ";

    return 0;
}