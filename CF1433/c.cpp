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
    vector<int> arr(n);
    int maxim = INT_MIN;
    int idx = -1;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i) {
        if (arr[i] > maxim && (i > 0 && arr[i] > arr[i - 1] || i < n - 1 && arr[i] > arr[i + 1])) {
            maxim = arr[i];
            idx = i + 1;
        }
    }
    cout << idx << "\n";
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