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

int Q(int l, int r) {
  if (l >= r)
    return -1;
  cout << "? " << l << " " << r << endl;
  int ans;
  cin >> ans;
  return ans;
}

void solve(int tc = 1) {
  int n;
  cin >> n;
  int smx = Q(1, n);
  int ans;
  if (smx == Q(1, smx)) {
    int L = 1, R = smx;
    while (L <= R) {
      int M = L + (R - L) / 2;
      if (Q(M, smx) == smx) {
        ans = M;
        L = M + 1;
      } else {
        R = M - 1;
      }
    }
  } else {
    int L = smx + 1, R = n;
    while (L <= R) {
      int M = L + (R - L) / 2;
      if (Q(smx, M) == smx) {
        ans = M;
        R = M - 1;
      } else {
        L = M + 1;
      }
    }
  }
  cout << "! " << ans << endl;
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int tc = 1;
  // cin >> tc;
  for (int t = 1; t <= tc; ++t) solve(t);

  return 0;
}