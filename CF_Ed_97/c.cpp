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
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) cin >> t[i];
    sort(t.begin(), t.end());
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= 2 * n; ++i)
        for (int j = n; j > 0; --j) dp[j] = min(dp[j], dp[j - 1] + abs(t[j - 1] - i));
    cout << dp[n] << "\n";
}


signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}