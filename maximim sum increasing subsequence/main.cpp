#include <bits/stdc++.h>

using namespace std;

int DP[1005];
int input[1005];
int N;

int main() {
    cin >> N;
    int i, j;
    for( i = 0 ; i < N ; ++i )
        cin >> input[i];

    // Build
    int Pos = 0 ;
    for( i = 0 ; i < N ; ++i )
        DP[i] = input[i];
    for( i = 1 ; i < N ; ++i ){
        for( j = 0 ; j < i ; ++j ){
            if( input[j] < input[i] ){
                DP[i] = max( DP[i], DP[j] + input[i]);
            }
        }
        if( DP[i] > DP[Pos] )
            Pos = i ;
    }
    int result = DP[Pos];
    cout << result << endl;
    // Retrace
    while ( result ){
        cout << input[Pos] << " " ;
        result -= input[Pos];
        while( DP[Pos] != result ){
            --Pos;
        }
    }
    return 0;
}