#include <bits/stdc++.h>

using namespace std;

int ROW, COL;

int kadane( int *arr, int *start, int *finish, int n){
    int gloMax = INT_MIN, sum = 0, i;
    *finish = -1;
    int local_start = 0;
    for( i = 0 ; i < n ; ++i){
        if( arr[i] > sum + arr[i] ){
            sum = arr[i];
            local_start = i;
        }
        else{
            sum += arr[i];
        }

        if( sum > gloMax ){
            gloMax = sum;
            *finish = i;
            *start = local_start;
        }
    }
    if( *finish != -1 )
        return gloMax;
    gloMax = arr[0];
    *finish = *start = 0;
    for( i = 1 ; i < n ; ++i)
        if( arr[i] > gloMax ) {
            gloMax = arr[i];
            *start = *finish = i;
        }
    return gloMax;
}

int findMAX( int M[][COL]){
    int globMax = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;
    int left, right, i;
    int temp[ROW], sum, start, finish;
    for( left = 0 ; left < COL; ++left){
        memset( temp, 0, sizeof( temp));
        for( right = left; right < COL ; ++right){
            for( i = 0 ; i < ROW ; ++i)
                temp[i] += M[i][right];
            sum = kadane( temp, &start, &finish, ROW);
            if( sum > globMax ){
                globMax = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }
}

int main() {

    return 0;
}