#include <bits/stdc++.h>

using namespace std;

int DP[1005];
int input[1005];
int N;

int main() {
    cin >> N;
    int i , j;

    for( i = 0 ; i < N ; ++i)
        cin >> input[i];

    for( i = 0 ; i < N ; ++i )
        DP[i] = 1;              // long increasing sub seq is atleast of length 1 at each posoition
    for( i = 1 ; i < N ; ++i){
        for( j = 0; j < i ; ++j )
            if( input[j] < input[i] )               // if inp[j] < inp [i] , then adding inp[i] to the longest sub
                DP[i] = max( DP[i], 1 + DP[j] );    // seq upto j will increase size of the sub sez till j by 1
    }

    cout << DP[N-1] << endl;
    return 0;
}