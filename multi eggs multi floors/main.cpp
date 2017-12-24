#include <bits/stdc++.h>

using namespace std;

int DP[105][100005];
int E;
int F;

int main() {
    cin >> E >> F;
    int i, j, x;
    time_t start = clock();
    for( i = 0 ; i <= E ; ++i ) {
        DP[i][0] = 0;
        DP[i][1] = 1;
    }
    for( j = 1 ; j <= F ; ++j ) {
        DP[0][j] = 0;
        DP[1][j] = j;
    }
    for( i = 2 ; i <= E ; ++i ){
        for( j = 2 ; j <=F ; ++j ){
                DP[i][j] = INT32_MAX;
                for( x = 1 ; x < j ; ++x ){
                    DP[i][j] = min( DP[i][j], 1 + max( DP[i-1][x-1], DP[i][j-x])) ;
                }
        }
    }
    time_t end = clock();
    cout << DP[E][F] << endl << (end - start) / CLOCKS_PER_SEC << endl;
    return 0;
}