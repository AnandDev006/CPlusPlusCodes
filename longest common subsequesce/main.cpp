#include <bits/stdc++.h>

using namespace std;

int DP[105][105];
int input1[105];
int input2[105];
vector< int> output;
int n;
int m;

void longest_common_subsequesce(){
    int i , j;
    // BUILD
    for( i = 0 ; i < n ; ++i){
        for( j = 0 ; j < m ; ++j){
            if( input1[i] != input2[j] )
                DP[i+1][j+1] = max( DP[i][j+1], DP[i+1][j]);
            else
                DP[i+1][j+1] = 1 + DP[i][j];
        }
    }
    int length = DP[n][m];
    // RETRACE
    i = n; j = m;
    while( i > 0 && j > 0 ){
        if( DP[i][j] == DP[i-1][j] )
            --i;
        else if( DP[i][j] == DP[i][j-1] )
            --j;
        else{
            output.push_back( input1[i-1]);
            --i; --j;
        }
    }
    while(length--)
        cout << output[length] << " ";
}

int main() {
    int i;
    cin >> n >> m;
    for( i = 0 ; i < n ; ++i)
        cin >> input1[i];
    for( i = 0 ; i < m ; ++i)
        cin >> input2[i];
    longest_common_subsequesce();
    return 0;
}