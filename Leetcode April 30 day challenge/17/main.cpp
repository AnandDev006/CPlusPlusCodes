/*
    author : Anand
    Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

    Example 1:

    Input:
    11110
    11010
    11000
    00000

    Output: 1
    Example 2:

    Input:
    11000
    11000
    00100
    00011

    Output: 3
*/

// #include <bits/stdc++.h>

#include <math.h>

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

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

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty() || grid[0].empty())
        return 0;

    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    auto isValid = [&](int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    };
    int ans = 0;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (visited[row][col] || grid[row][col] == '0') continue;
            ans++;
            queue<pair<int, int>> q;
            q.push({row, col});
            visited[row][col] = true;
            while (!q.empty()) {
                pair<int, int> node = q.front();
                q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nextRow = node.first + dirs[dir][0];
                    int nextCol = node.second + dirs[dir][1];
                    if (isValid(nextRow, nextCol) && !visited[nextRow][nextCol] && grid[nextRow][nextCol] == '1') {
                        q.push({nextRow, nextCol});
                        visited[nextRow][nextCol] = true;
                    }
                }
            }
        }
    }
    return ans;
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