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
    string s;
    cin >> n >> s;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '1' && s[i + 1] == '1') ++c1;
        if (s[i] == '0' && s[i + 1] == '0') ++c2;
    }
    cout << max(c1, c2) << endl;
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