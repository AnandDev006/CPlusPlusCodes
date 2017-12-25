#include <bits/stdc++.h>

using namespace std;

int DP[1005][1005];
string S[1005];
int N;
int width;

int badness( int i, int j){
    int val = 0;
    for( int x = i ; x <= j ; ++x )
        val += S[x].length();
    val += ( j - i ) ;
    if( val > width )
        val = INT32_MAX ;
    else
        val =  (int)pow( width - val , 3);
    return val;
}

void print( int i, int j){
    for( int x = i ; x <= j ; ++x )
        cout << S[x] << " ";
    cout << endl;
}

int main() {
    cin >> N >> width ;
    int i, j;
    for( i = 0 ; i < N ; ++i )
        cin >> S[i];

    for( i = 0 ; i < N ; ++i ) {
        for( j = i ; j < N ; ++j ){
            DP[i][j] = badness( i, j);
        }
    }
    vector< pair< int, int>> output;
    i = j = N-1 ;
    int counter = 0;
    int cost = 0 ;
    while( j >= 0 ){
        if( DP[i-1][j] != INT32_MAX && i ) {
            --i;
            ++counter;
        }
        else{
            output.push_back( make_pair( i, j));
            cost += DP[i][j];
            --i;
            j = j - counter - 1;
            counter = 0;
        }
    }
    cout << "Cost : " << cost << endl ;
    for( i = output.size() - 1 ; i >= 0 ; --i ){
        print( output[i].first, output[i].second );
    }
    return 0;
}