#include <bits/stdc++.h>

using namespace std;

int DP[1005][1005]; // L1 * L2
string input1;
string input2;
string output;

int main() {                    // converts input1 into input2
    cin >> input1 >> input2;

    int len1 = input1.length() , len2 = input2.length();
    int i , j;

    // Build
    for( i = 0 ; i <= len2 ; ++i )
        DP[i][0] = i;
    for( j = 0 ; j <= len1 ; ++j )
        DP[0][i] = i;
    for( i = 1 ; i <= len2 ; ++i ){
        for( j = 1 ; j <= len1 ; ++j )
            if( input1[j-1] == input2[i-1] )
                DP[i][j] = DP[i-1][j-1];
            else
                DP[i][j] = 1 + min( DP[i-1][j-1] , min( DP[i-1][j], DP[i][j-1]) );  // DP[i-1][j] -> insert
                                                                                    // DP[i-1][j-1] -> edit
                                                                                    // DP[i][j-1] -> delete
    }

    int result = DP[len2][len1];
    cout << endl << result << endl ;

    // retrace
    i = len2; j = len1;
    while( i && j ){
        if( input1[j-1] == input2[i-1] ){
            --i;
            --j;
        }
        else if( DP[i][j] == DP[i-1][j-1] + 1 ){
            cout << input1[j-1] << " -> " << input2[i-1] << endl;
            --i;
            --j;
        }
        else if( DP[i][j] == DP[i][j-1] + 1 ){
            cout << input1[j-1] << " -> " << endl;
            --j;
        }
        else if( DP[i][j] == DP[i-1][j] + 1 ){
            cout << "  -> " << input1[j-1] << endl;
            --i;
        }
    }

    return 0;
}