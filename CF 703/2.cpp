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

  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i)
    cin >> x[i] >> y[i];

  if (n & 1) {
    cout << 1 << "\n";
  } else {
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    cout << (x[n / 2] - x[n / 2 - 1] + 1) * (y[n / 2] - y[n / 2 - 1] + 1) << "\n";
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; ++t) solve(t);

  return 0;
}