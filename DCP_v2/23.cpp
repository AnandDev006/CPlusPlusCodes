/*
  author : Anand
    Problem 23
    This problem was asked by Google.

    You are given an M by N matrix consisting of booleans that represents a board. Each True boolean represents a wall. Each False boolean represents a tile you can walk on.

    Given this matrix, a start coordinate, and an end coordinate, return the minimum number of steps required to reach the end coordinate from the start. If there is no possible path, then return null. You can move up, left, down, and right. You cannot move through walls. You cannot wrap around the edges of the board.

    For example, given the following board:

    [[f, f, f, f],
    [t, t, f, t],
    [f, f, f, f],
    [f, f, f, f]]
    and start = (3, 0) (bottom left) and end = (0, 0) (top left), the minimum number of steps required to reach the end is 7, since we would need to go through (1, 2) because there is a wall everywhere else on the second row.
*/

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define int long long
#define ll long long

#ifndef ONLINE_JUDGE
#define debug(...) cerr << "\t" << #__VA_ARGS__ << " : " << (__VA_ARGS__) << endl;
#else
#define debug(...) 42
#endif

const int INF = 1e18 + 5;
const int MOD = 1000000007;
const int N = 1e7;
const int K = 25;

int getNumSteps(vector<vector<char>> matrix, pair<int, int> start, pair<int, int> end) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> dist(rows, vector<int>(cols, -1));
    queue<pair<int, int>> Q;
    int dr[] = {0, -1, 0, 1};
    int dc[] = {1, 0, -1, 0};

    Q.push(start);
    dist[start.first][start.second] = 0;

    while (!Q.empty()) {
        pair<int, int> u = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = u.first + dr[i];
            int y = u.second + dc[i];
            if (x >= 0 && y >= 0 && x < rows && y < cols && matrix[x][y] == 'f' && dist[x][y] == -1) {
                Q.push({x, y});
                dist[x][y] = dist[u.first][u.second] + 1;
                if (make_pair(x, y) == end) {
                    return dist[x][y];
                }
            }
        }
    }
    return -1;
}

void solve() {
    assert(getNumSteps({{'f', 'f', 'f', 'f'},
                        {'t', 't', 'f', 't'},
                        {'f', 'f', 'f', 'f'},
                        {'f', 'f', 'f', 'f'}},
                       {3, 0}, {0, 0}) == 7);
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}