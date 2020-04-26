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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> cs(n);
    for ( int i = 1; i < n - 1 ; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            cs[i] = 1;
        }
    }
    for( int i = 1 ; i < n ; i++) {
        cs[i] += cs[i-1];
    }
    int maxPeakC = 0, l = 0;
    for( int i = k-1 ; i < n ; ++i) {
        if( maxPeakC < (cs[i-1] - cs[i-k+1]) ) {
            maxPeakC = cs[i-1] - cs[i-k+1];
            l = i-k+1;
        }
    }
    cout << maxPeakC + 1 << " " << l + 1<< "\n";
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