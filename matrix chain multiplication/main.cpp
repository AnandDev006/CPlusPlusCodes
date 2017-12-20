#include <bits/stdc++.h>

using namespace std;

int DP[105][105];
int input[105];
int n;

void MCM(){
    int l, i, j, k;
    int minim;
    l = 1;
    // for l = 1 , cost is 0;
    for( i = 0 ; i < n ; ++i)
        DP[i][i] = 0;

    for( l = 2; l < n ; ++l){
        for( i = 0 ; i < n - l ; ++i){
            j = i + l;
            minim = INT32_MAX;
            for( k = i + 1; k < j ; ++k){
                minim = min( minim, DP[i][k-1] + DP[k][j-1] + input[i]*input[k]*input[j] );
            }
            DP[i][j-1] = minim;
        }
    }
    cout << DP[0][n-2] << endl;
}

int main() {
    cin >> n;
    for( int i = 0 ; i < n ; ++i)
        cin >> input[i];
    MCM();
    return 0;
}