#include <bits/stdc++.h>
#define MAXN 5

using namespace std;

int G[MAXN][MAXN];
int mat[MAXN][MAXN][MAXN];

void print( int temp[MAXN][MAXN]){
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j)
            cout << temp[i][j] << " ";
        cout << endl;
    }
    cout << endl ;
}

int main() {
    for( int i = 0 ; i < MAXN ; ++i )
        for( int j = 0 ; j < MAXN ; ++j ) {
            cin >> G[i][j];
            mat[1][i][j] = G[i][j];
        }
    print( mat[1]);
    for( int l = 2 ; l <= MAXN - 1 ; ++l ){
        for( int i = 0 ; i < MAXN ; ++i ){
            for( int j = 0 ; j < MAXN ; ++j ){
                mat[l][i][j] = 0 ;
                for( int k = 0 ; k < MAXN ; ++k ){
                    mat[l][i][j] += mat[l-1][i][k]*G[k][j];
                }
            }
        }
        print( mat[l]);
    }
    return 0;
}