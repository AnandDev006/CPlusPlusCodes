#include <bits/stdc++.h>

using namespace std;

int DP[1005];
int input[1005];
int N;

int main() {
    cin >> N;
    int i;
    for( i = 0 ; i < N ; ++i )
        cin >> input[i];
    int height = INT32_MAX, start = 0, finish = 0;
    DP[0] = input[0];
    for( i = 1 ; i < N ; ++i ){
        height = min( height, input[i]);
        DP[i] = max( DP[i-1], max( (i-start+1)*height , input[i] ) );
        if( input[i] == 0 ){
            start = finish = i + 1;
            height = INT32_MAX ;
        }
    }
    cout << DP[N-1] << endl ;
    return 0;
}