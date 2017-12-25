#include <bits/stdc++.h>

using namespace std;

int DP[10005];
int input[10005][10005];
int row, col;

int max_area_histogram( int arr[], int n){
    int maxim = arr[0], start = 0 , height = INT32_MAX;
    for( int i = 1 ; i < n ; ++i ){
        height = min( height, arr[i]);
        maxim = max( maxim, max( arr[i], (i-start+1)*height));
        if( arr[i] == 0 ){
            start = i + 1;
            height = INT32_MAX;
        }
    }
    return maxim;
}

int main() {

    cin >> row >> col ;
    int i, j;
    for( i = 0 ; i < row ; ++i )
        for( j = 0 ; j < col ; ++j )
            cin >> input[i][j];
    int max_area = INT32_MIN;
    for( i = 0 ; i < row ; ++i ){
        for( j = 0 ; j < col ; ++j ){
            if( input[i][j] == 0 )
                DP[j] = 0;
            else
                DP[j] += input[i][j];
            max_area = max( max_area, max_area_histogram( DP, col));
        }
    }
    cout << max_area << endl;
    return 0;
}

/*
4 6
1 0 0 1 1 1
1 0 1 1 0 1
0 1 1 1 1 1
0 0 1 1 1 1
 */