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

void recur(const vector<int> &a, vector<int> &b, int l, int r, int d) {
  if (l > r) return;
  int maxIdx = l;
  for (int i = l; i <= r; ++i)
    if (a[i] > a[maxIdx])
      maxIdx = i;
  b[maxIdx] = d;
  recur(a, b, l, maxIdx - 1, d + 1);
  recur(a, b, maxIdx + 1, r, d + 1);
}

void solve(int tc = 1) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  recur(a, b, 0, n - 1, 0);
  for (int x : b) cout << x << " ";
  cout << endl;
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; ++t) solve(t);

  return 0;
}