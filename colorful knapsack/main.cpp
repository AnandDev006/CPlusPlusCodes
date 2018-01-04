#include <bits/stdc++.h>

using namespace std;

int DP[101][10000];
pair< int, int> WC[101];
int cpos[101];
int N, M, X;

auto cmp = []( pair< int, int> a, pair< int, int> b){
    if( a.second == b.second )
        return a.first < b.first ;
    else
        return a.second < b.second;
};

void setDP( int c, int w){
    int pos;

    if( c == 1 )
        pos = 0;
    else
        pos = 1 + cpos[c-1];

    for( ; pos <= cpos[c] ; ++pos ) {
        if( c == 1 ){
            if( w < WC[pos].first )
                DP[c][w] = max( DP[c][w], 0) ;
            else
                DP[c][w] = max( DP[c][w-1], WC[pos].first);
        }
        else{
            if( w <= WC[pos].first )
                DP[c][w] = max( DP[c][w], 0);
            else if (DP[c - 1][w - WC[pos].first] == 0)
                    DP[c][w] = max( DP[c][w], 0);
            else{
                if( DP[c - 1][w - WC[pos].first] + WC[pos].first <= X )
                    DP[c][w] = max( DP[c][w], DP[c - 1][w - WC[pos].first] + WC[pos].first);
                else
                    DP[c][w] = max( DP[c][w], 0);
            }
        }
    }
}

int main(){
    cin >> N >> M >> X;
    int i, j;
    for( i = 0 ; i < N ; ++i )
        cin >> WC[i].first;
    for( i = 0 ; i < N ; ++i )
        cin >> WC[i].second;

    sort( WC, WC + N, cmp);
    for( i = 0 ; i < N ; ++i ) {
        if( WC[i].second != WC[i+1].second )
            cpos[WC[i].second] = i;
    }
    for( j = 0 ; j <= X ; ++j )
        DP[0][j] = 0 ;
    for( i = 0 ; i <= M ; ++i )
        DP[i][0] = 0;

    for( i = 1 ; i <= M ; ++i ){
        for( j = 1 ; j <= X ; ++j ){
            setDP( i, j);
        }
    }
    int result = DP[M][X] ;
    if( result )
        cout << X - result ;
    else
        cout << "-1" << endl ;
    return 0;
}