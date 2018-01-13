#include <bits/stdc++.h>

using namespace std;

int main() {
    int maxLen = INT32_MIN;
    int left, right;
    int csum [1005];
    memset( csum, 0, sizeof(csum));
    int input [] = { 8,1,8,1,8,1,6,3,5,8,7,4,23};
    int n = sizeof(input)/sizeof(input[0]);
    csum[0] = 0;
    for( int i = 1 ; i <= n ; ++i )
        csum[i] = csum[i-1] + input[i-1] ;
    for( int l = 2 ; l <= n ; l+=2 ){
        for( int i = 0 ; i <= n - l ; ++i ){
            int j = i + l - 1;
            int mid = ( i + j ) / 2 ;
            if( ( csum[mid+1] - csum[i] ) == ( csum[j+1] - csum[mid+1] ) )
                if( maxLen < l ){
                    maxLen = l;
                    left = i ;
                    right = j;
                }
        }
    }
    cout << maxLen << endl << left << endl << right << endl;
    return 0;
}