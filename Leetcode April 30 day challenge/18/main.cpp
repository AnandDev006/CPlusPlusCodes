/*
    author : Anand
    Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

    Note: You can only move either down or right at any point in time.

    Example:

    Input:
    [
    [1,3,1],
    [1,5,1],
    [4,2,1]
    ]
    Output: 7
    Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

#include <bits/stdc++.h>

// #include <math.h>

// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include <map>
// #include <queue>
// #include <set>
// #include <stack>
// #include <utility>
// #include <vector>

#define sz(a) int((a).size())
#define ll long long
#define pb push_back
#define mp(a, b) make_pair(ll(a), ll(b))
#define F first
#define S second
#define all(c) (c).begin(), (c).end()
#define PI 3.1415926535897932384626

using namespace std;

const int INF = 1e9 + 5;
const int MOD = 1000000007;
const double ZERO = 10e-9;
const int N = 3e5, M = N;

int DP[N];

int minPathSum(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty())
        return 0;

    int H = grid.size();
    int W = grid[0].size();
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 && j == 0)
                continue;
            else if (i == 0)
                grid[i][j] += grid[i][j - 1];
            else if (j == 0)
                grid[i][j] += grid[i - 1][j];
            else
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }
    }
    return grid[H - 1][W - 1];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}