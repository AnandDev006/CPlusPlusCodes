/*
  author : Anand
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

const int INF = 1e18 + 5;
const int MOD = 1000000007;
const int N = 1e7;
const int K = 25;

void solve(int tc = 1) {
  int n;
  cin >> n;
  vector<int> c(3);

  int x;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    ++c[x % 3];
  }

  int ans = 0;
  for (int it = 0; it < 2; ++it) {
    for (int i = 0; i < 3; ++i) {
      if (c[i] > n / 3) {
        ans += c[i] - n / 3;
        c[(i + 1) % 3] += c[i] - n / 3;
        c[i] = n / 3;
      }
    }
  }

  cout << ans << endl;
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; ++t) solve(t);

  return 0;
}