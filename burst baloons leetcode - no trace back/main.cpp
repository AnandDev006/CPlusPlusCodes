#include <bits/stdc++.h>

using namespace std;

int DP[1005][1005];
int input[1005];
int N;

int main() {
    cin >> N ;
    int i, j, k, len;
    for( i = 0 ; i < N ; ++i )
        cin >> input[i];
    for( len = 1 ; len <= N ; ++len ){
        for( i = 0 ; i < N - len + 1 ; ++i ){
            j = i + len - 1;
            int left = 1;
            int right = 1;
            if( i )
                left = input[i-1];
            if( j != N-1 )
                right = input[j+1];
            DP[i][j] = INT32_MIN;
            for( k = i ; k <= j ; ++k ){
                int before = 0;
                int after = 0;
                if( k != i )
                    before = DP[i][k-1];
                if( k != j )
                    after = DP[k+1][j];
                DP[i][j] = max( DP[i][j], before + after + left*input[k]*right );
            }
        }
    }
    int result = DP[0][N-1];
    cout << result << endl ;
    return 0;
}