#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define int long long
#define ll long long
#define dbg(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int INF = 1e9 + 5;
const int MOD = 1000000007;
const double ZERO = 10e-9;
const int N = 3e5, M = N;

void fileIO() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
}

void solve () {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for ( int i = 0 ;  i < n ; i++) cin >> a[i];

    vector<int> csum(2 * k + 2, 0);

    for ( int i = 0 ; i < n / 2 ; ++i) {        
        int minim = min(a[i], a[n - i - 1]);
        int maxim = max(a[i], a[n - i - 1]);

        csum[1] += 2; // if all had to change both

        // if only 1 change was needed it is in range min+1 <= x <= max + k
        csum[minim + 1]--;
        csum[maxim + k + 1]++;

        // if no change is needed
        csum[minim + maxim]--;
        csum[minim + maxim + 1]++;
    }
    int sum = 0;
    int ans = +INF;
    for ( int i = 1 ; i < 2 * k + 2 ; i++) {
        sum += csum[i];
        ans = min(ans, sum);
    }
    cout << ans << '\n';
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