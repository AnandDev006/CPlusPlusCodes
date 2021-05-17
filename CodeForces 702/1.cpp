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
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int cnt = 0;
  for (int i = 1; i < n; ++i) {
    int minim = min(a[i], a[i - 1]);
    int maxim = max(a[i], a[i - 1]);
    while (2 * minim < maxim) {
      minim *= 2;
      ++cnt;
    }
  }
  cout << cnt << endl;
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; ++t) solve(t);

  return 0;
}