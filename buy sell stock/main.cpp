#include<bits/stdc++.h>

using namespace std;

int DP[105][1005];
int Prices[1005];
int P;
int K;

int main(){
    cin >> K >> P;
    int i, j, m;
    for( i = 0 ; i < P ; ++i )
        cin >> Prices[i] ;
    // Build
    for( i = 0 ; i <= K ; ++i )
        DP[i][0] = 0;
    for( j = 0 ; j < P ; ++j )
        DP[0][j] = 0;
    for( i = 1 ; i <= K ; ++i ){
        for( j = 1 ; j < P ; ++j ){
            if( j < i )
                DP[i][j] = DP[i-1][j];
            else{
                DP[i][j] = DP[i][j-1];
                for( m = 0 ; m < j ; ++m ){
                    DP[i][j] = max( DP[i][j], ( Prices[j] - Prices[m] ) + DP[i-1][m] );
                }
            }
        }
    }
    int result = DP[K][P-1];
    vector< int> sell;
    vector< int> buy;
    // Retrace
    i = K; j = P-1;
    while( j > 0 ){
        if( DP[i][j] == DP[i][j-1] )
            --j;
        else{
            sell.push_back( j );
            int temp = DP[i][j] - Prices[j] ;
            --i;
            while( DP[i][j] - Prices[j] != temp ){
                --j;
            }
            buy.push_back( j);
        }
    }
    cout << "Profit : " << result << endl ;
    for( i = 0 ; i < sell.size() ; ++i )
        cout << "Buy : " << buy[i] << " \t Sell : " << sell[i] << endl ;
    return 0;
}
