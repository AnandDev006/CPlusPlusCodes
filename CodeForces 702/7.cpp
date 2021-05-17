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

int find(const vector<int> &b, int v) {
  int l = 0, r = b.size();
  while (l < r) {
    int m = l + (r - l) / 2;
    if (b[m] >= v)
      r = m;
    else
      l = m + 1;
  }
  return r;
}

void solve(int tc = 1) {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> b(n);
  int mx = -INF;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
    mx = max(mx, sum);
    b[i] = mx;
  }
  
  int x;
  int ans;
  for (int i = 0; i < m; ++i) {
    cin >> x;
    if (sum > 0) {
      int numRot = 0;
      if (x > mx)
        numRot = ((x - mx) + (sum - 1)) / sum;
      ans = n * numRot + find(b, x - numRot * sum);
    } else {
      if (x > mx) {
        ans = -1;
      } else {
        ans = find(b, x);
      }
    }
    cout << ans << " ";
  }
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