// https://www.hackerrank.com/challenges/equal/problem

#include <bits/stdc++.h>

using namespace std;

int T, N;
int d[100010];

int main() {
    cin >> T;
    while( T--) {
        cin >> N;
        for( int i = 0 ; i < N ; ++i)
            cin >> d[i];
        int M = *min_element( d, d+ N);
        int r = INT_MAX;
        for( int t = M - 4 ; t <= M ; ++t ) {
            int s = 0;
            for( int i = 0 ; i < N ; ++i){
                int D = abs( d[i] - t );
                s += D/5, D%= 5;
                s += D/2, D%= 2;
                s += D;
            }
            r = min( r, s);
        }
        cout << r << endl;
    }
    return 0;
}