#include <bits/stdc++.h>

using namespace std;

int main() {
    int Q;
    cin >> Q;
    while( Q--) {
        int N;
        int x, cumilative = 0, sumSubSeq = 0 , sumSubArray = INT_MIN, largest = INT_MIN;
        cin >> N;
        for( int i = 0 ; i < N ; ++i) {
            cin >> x;

            if (x > 0)
                sumSubSeq += x;

            largest = max( largest, x);

            cumilative = max( x, cumilative + x);

            sumSubArray = max( sumSubArray, cumilative);

        }

        cout << sumSubArray << ' ' ;

        if( largest >= 0 )
            cout << sumSubSeq << endl;
        else
            cout << largest << endl;
    }
    return 0;
}