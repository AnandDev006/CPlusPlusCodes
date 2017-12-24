#include <bits/stdc++.h>

using namespace std;

int DP[2][100005]; // include , not include
int input[100005];
int N;

int main() {
    cin >> N;
    int i, j;
    for( i=0 ; i < N ; ++i )
        cin >> input[i];

    DP[0][0] = input[0];
    DP[1][0] = 0;
    DP[0][1] = input[1];
    DP[1][1] = max( 0, DP[0][0]);

    for( i = 2 ; i < N ; ++i ){
        DP[0][i] = input[i] + DP[1][i-1];
        DP[1][i] = max( DP[0][i-1], DP[1][i-1] );
    }
    cout << max( DP[0][N-1], DP[1][N-1]) << endl ;
    return 0;
}