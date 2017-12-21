#include <bits/stdc++.h>

using namespace std;

int DP[1005][1005];
int coins[1005];
int N;
int sum;

int main() {

    cin >> N >> sum;
    int i, j;
    for( i = 0 ; i < N ; ++i )
        cin >> coins[i];

    for( j = 0 ; j <= sum ; ++j )
        DP[0][j] = 0;
    for( i = 0 ; i <= N ; ++i )
        DP[i][0] = 1;
    for( i = 1 ; i <= N ; ++i ){
        for( j = 1 ; j <= sum ; ++j ){
            if( j < coins[i-1] )
                DP[i][j] = DP[i-1][j];
            else
                DP[i][j] = DP[i-1][j] + DP[i][j-coins[i-1]] ;
        }
    }
    cout << DP[N][sum] << endl;
    return 0;
}