#include <bits/stdc++.h>

#define MAXN 13

using namespace std;

int DP[2][MAXN];        // include , not include
vector< int> G[MAXN] = {{1,  2,  3},
                        {4,  5,  6},
                        {7,  8,  9},
                        {10, 11, 12},
                        {},
                        {},
                        {},
                        {},
                        {},
                        {},
                        {},
                        {},
                        {}
};

int Cost[MAXN] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14};

void DFS_DP_Soln(int Node, int Parent){
    int sum[2] = { 0, 0};
    for( auto v : G[Node]){
        DFS_DP_Soln( v, Node);
        sum[0] += DP[1][v];
        sum[1] += max( DP[0][v], DP[1][v] );
    }
    DP[0][Node] = Cost[Node] + sum[0];
    DP[1][Node] = sum[1];
}

int main() {
    int i, j;
    DFS_DP_Soln( 0, -1);
    cout << max( DP[0][0], DP[1][0]) << endl;
    return 0;
}