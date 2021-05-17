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
const int N = 1e7;
const int K = 25;

void solve(int tc = 1) {
  int n, d;
  cin >> n >> d;
  int m1, m2;
  m1 = m2 = INF;
  int x;
  bool needChange = false;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    if (x < m1) {
      m2 = m1;
      m1 = x;
    } else if (x < m2) {
      m2 = x;
    }
    if (x > d) {
      needChange = true;
    }
  }
  if (needChange && m1 + m2 > d) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
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