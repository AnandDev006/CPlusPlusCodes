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
    int notFirst = -1;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (notFirst == -1 && i > 0 && arr[i] != arr[0]) notFirst = i + 1;
    }
    if (notFirst == -1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 1; i < n; ++i) {
        if (arr[i] == arr[0])
            cout << notFirst << " " << i + 1 << "\n";
        else
            cout << 1 << " " << i + 1 << "\n";
    }
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