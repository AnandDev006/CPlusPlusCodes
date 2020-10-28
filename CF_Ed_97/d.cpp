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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int pos = 1;
    int depth = 0;
    int width = 1;
    while (pos < n) {
        ++depth;
        int start = pos;

        for (int i = 0; i < width && pos < n; ++i) {
            ++pos;
            while (pos < n && a[pos] > a[pos - 1]) ++pos;
        }

        // debug(a[pos - 1]);
        // debug(pos);

        width = pos - start;
    }
    cout << depth << '\n';
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