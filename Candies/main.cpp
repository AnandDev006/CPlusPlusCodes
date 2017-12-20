#include <bits/stdc++.h>

using namespace std;

int N;
long long d[1000005];

int main() {

    cin >> N;
    for( long i = 0; i < N; ++i)
        cin >> d[i];

    int c = 1;
    int r = 0;
    for( int i = 1 ; i < N ; ++i) {
        if( i == 1 )

        if( d[i] > d[i-1] )
            r += ++c ;
        else {
            c = 1;
            r += c;
        }
    }

    return 0;
}