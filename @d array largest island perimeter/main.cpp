#include <bits/stdc++.h>
#define ROW 5
#define COL 5

using namespace std;

bool isSafe( int M[][COL], int row, int col, int visited[][COL]){
    return ( ( row >= 0 ) && ( row < ROW ) &&
             ( col >= 0 ) && ( col < COL ) &&
              M[row][col] && !visited[row][col] );
}

void DFS( int M[][COL], int row, int col, int visited[][COL], int &area){
    static int rowNbr[] = { 0,-1, 0, 1,-1,-1, 1, 1};
    static int colNbr[] = {-1, 0, 1, 0,-1, 1,-1, 1};
    visited[row][col] = true;
    for( int k = 0 ; k < 8 ; ++k ){
        if( isSafe( M, row + rowNbr[k], col + colNbr[k], visited ) ){
            if( k <= 3 )
                area += 2;
            else
                area += 4;
            DFS( M, row + rowNbr[k], col + colNbr[k], visited, area );
        }
    }
}

int largest( int M[][COL]){
    int visited[ROW][COL];
    memset( visited, 0, sizeof(visited));
    int result = INT32_MIN;
    for( int i = 0 ; i < ROW ; ++i ){
        for( int j = 0 ; j < COL ; ++j ) {
            if( M[i][j] && !visited[i][j] ){
                int area = 4;
                DFS( M, i, j, visited, area);
                result = max( result, area);
            }
        }
    }

}

int main()
{
    int M[][COL]={  {1, 1, 0, 0, 0},
                    {0, 1, 0, 0, 1},
                    {1, 0, 0, 1, 1},
                    {0, 0, 0, 0, 0},
                    {1, 0, 1, 0, 1}
    };

    cout << "Largest island area : " << largest(M) << endl;

    return 0;
}