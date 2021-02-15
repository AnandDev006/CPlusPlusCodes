/*
  author : Anand

    Problem 19
    This problem was asked by Facebook.

    A builder is looking to build a row of N houses that can be of K different colors. He has a goal of minimizing cost while ensuring that no two neighboring houses are of the same color.

    Given an N by K matrix where the nth row and kth column represents the cost to build the nth house with kth color, return the minimum cost which achieves this goal.
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

int getMinCost(vector<vector<int>> matrix, int houses, int colors) {
    int prevMin = 0, prevMinIdx = -1, prevSecondMin = 0;
    for (int i = 0; i < houses; ++i) {
        int curMin = INF, curSecondMin = INF, curMinIdx = 0;
        for (int j = 0; j < colors; ++j) {
            if (prevMinIdx == j) {
                matrix[i][j] += prevSecondMin;
            } else {
                matrix[i][j] += prevMin;
            }

            if (curMin > matrix[i][j]) {
                curSecondMin = curMin;
                curMin = matrix[i][j];
                curMinIdx = j;
            } else if (curSecondMin > matrix[i][j]) {
                curSecondMin = matrix[i][j];
            }
        }
        prevMin = curMin;
        prevMinIdx = curMinIdx;
        prevSecondMin = curSecondMin;
    }
    int ans = INF;
    for (int j = 0; j < colors; ++j) {
        ans = min(ans, matrix[houses - 1][j]);
    }
    return ans;
}

void solve() {
    assert(getMinCost({{7, 3, 8, 6, 1, 2},
                       {5, 6, 7, 2, 4, 3},
                       {10, 1, 4, 9, 7, 6}},
                      3, 6) == 4);
    assert(getMinCost({{7, 3, 8, 6, 1, 2},
                       {5, 6, 7, 2, 4, 3},
                       {10, 1, 4, 9, 7, 6},
                       {10, 1, 4, 9, 7, 6}},
                      4, 6) == 8);
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