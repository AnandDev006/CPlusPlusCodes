/*
  author : Anand
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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    vector<vector<vector<vector<int>>>> dp(n + 1, vector<vector<vector<int>>>(m + 1, vector<vector<int>>(m, vector<int>(k, -INF))));

    dp[0][0][0][0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int cnt = 0; cnt < m / 2 + 1; ++cnt) {
                for (int rem = 0; rem < k; ++rem) {
                    if (dp[i][j][cnt][rem] == -INF) continue;
                    int next_i = (j == m - 1 ? i + 1 : i);
                    int next_j = (j == m - 1 ? 0 : j + 1);
                    if (i != next_i) {
                        dp[next_i][next_j][0][rem] = max(dp[next_i][next_j][0][rem], dp[i][j][cnt][rem]);
                    } else {
                        dp[next_i][next_j][cnt][rem] = max(dp[next_i][next_j][cnt][rem], dp[i][j][cnt][rem]);
                    }
                    if (cnt + 1 <= m / 2) {
                        int next_rem = (rem + arr[i][j]) % k;
                        if (i != next_i) {
                            dp[next_i][next_j][0][next_rem] = max(dp[next_i][next_j][0][next_rem], dp[i][j][cnt][rem] + arr[i][j]);
                        } else {
                            dp[next_i][next_j][cnt + 1][next_rem] = max(dp[next_i][next_j][cnt + 1][next_rem], dp[i][j][cnt][rem] + arr[i][j]);
                        }
                    }
                }
            }
        }
    }
    cout << max((int)0, dp[n][0][0][0]) << "\n";
}

signed main() {
    cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}