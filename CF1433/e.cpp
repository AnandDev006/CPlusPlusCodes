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
const int N = 21;

long long f[N];

void solve() {
    int n;
    cin >> n;
    f[0] = 1;
    for (int i = 1; i < N; ++i) {
        f[i] = f[i - 1] * i;
    }

    long long ans = f[n] / f[n / 2] / f[n / 2];
    ans = ans * f[n / 2 - 1];
    ans = ans * f[n / 2 - 1];
    ans /= 2;

    cout << ans << endl;
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