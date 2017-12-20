#include <bits/stdc++.h>

using namespace std;

int DP[105][105];
int freq[105];
int key[105];
int N;

int getSum( int i, int j){
    int sum = 0;
    for( int x = i; x <= j ; ++x )
        sum += freq[x];
    return sum;
}

int main() {
    cin >> N;
    int i, j, k, l, minim, sum;

    for( i = 0 ; i < N ; ++i)
        cin >> key[i] >> freq[i]; // input should be in INCREASING ORDER OF KEY

    for( i = 0 ; i < N ; ++i)
        DP[i][i] = freq[i];

    for( l = 2 ; l <= N ; ++l){
        for( i = 0 ; i <= N - l ; ++i){
            j = i + l - 1;
            sum = getSum(i, j);
            DP[i][j] = INT32_MAX;
            for( k = i ; k <= j ; ++k)
                DP[i][j] = min( DP[i][j], sum + ( k == i ? 0 : DP[i][k-1] ) + ( k == j ? 0 : DP[k+1][j] ) );
        }
    }
    cout << DP[0][N-1];
    return 0;
}