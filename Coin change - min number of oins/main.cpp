#include <bits/stdc++.h>

using namespace std;

int DP[1005][1005];
int coins[1005];
int N;
int sum;

int main() {
    cin >> N >> sum ;
    int i, j;
    for( i = 0 ; i < N ; ++i )
        cin >> coins[i];

    // Build
    for( j = 0 ; j <= sum ; ++j )
        DP[0][j] = INT32_MAX - sum;
    for( i = 0 ; i <= N ; ++i )
        DP[i][0] = 0;
    for( i = 1 ; i <= N ; ++i ){
        for( j = 1 ; j <= sum ; ++j ){
            if( j < coins[i-1] )
                DP[i][j] = DP[i-1][j];
            else
                DP[i][j] = min( DP[i-1][j], 1 + DP[i][j-coins[i-1]] );
        }
    }
    int result = DP[N][sum];
    // Retrace
    i = N ; j = sum;
    vector<int> output;
    while( j != 0 ){
        if( j < coins[i-1] )
            --i;
        else if( DP[i][j] == 1 + DP[i][j-coins[i-1]] ){
            output.push_back( coins[i-1]);
            j -= coins[i-1];
        }
        else if( DP[i][j] == DP[i-1][j] )
            --i;
    }
    cout << endl << result << endl;
    while( result--){
        cout << output[result] << " ";
    }
    return 0;
}