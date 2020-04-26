#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define int long long
#define ll long long
#define dbg(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int INF = 1e18 + 5;
const int MOD = 1000000007;
const double ZERO = 10e-9;
const int N = 3e5, M = N;

void fileIO() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
}

void solve() {
    int n, a, b , c, d;
    cin >> n >> a >> b >> c >> d;
    if ( (n * (a - b) < (c - d) && n * (a + b) < (c - d)) || (n * (a - b) > (c + d) && n * (a + b) > (c + d)) ) {
        cout << "NO\n" ;
    } else {
        cout << "YES\n";
    }
}

signed main() {
    cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}