#include <bits/stdc++.h>

using namespace std;

bool DP[105][10000];
int input[105];
int N;
int sum;

int main() {
    cin >> N;
    cin >> sum;
    int i , j;

    for( i = 0 ; i < N ; ++i )
        cin >> input[i];

    for( i = 0 ; i < sum ; ++i)
        DP[0][i] = false;
    for( i = 0; i < N ; ++i )
        DP[i][0] = true;

    for( i = 0 ; i < N ; ++i ){
        for( j = 1 ; j <= sum ; ++j)
            if( j < input[i] )
                DP[i+1][j] = DP[i][j];
            else
                DP[i+1][j] = DP[i][j] || DP[i][j-input[i]] ;
    }
    cout << DP[N][sum-1] << endl;
    return 0;
}