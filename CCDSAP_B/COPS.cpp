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
    int M, x, y;
    cin >> M >> x >> y;
    vector<int> H(100);
    for (int i = 0; i < M; ++i) {
        int t;
        cin >> t;
        H[t - 1] = 1;
    }
    vector<int> nearest(100);
    int nearestCop = -1;
    for (int i = 0; i < 100; ++i) {
        if (H[i] == 1) nearestCop = i;
        nearest[i] = nearestCop;
    }

    nearestCop = -1;
    for (int i = 99; i >= 0; --i) {
        if (H[i] == 1) nearestCop = i;
        nearest[i] = ((nearest[i] == -1 || abs(i - nearestCop) < abs(i - nearest[i])) ? nearestCop : nearest[i]);
    }
    int ans = 0;
    for (int i = 0; i < 100; ++i) {
        if (abs(i - nearest[i]) > x * y) {
            ++ans;
        }
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}