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
  vector<pair<int, int> > a(n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
    sum += a[i].first;
  }
  sort(a.begin(), a.end());
  vector<int> ans;

  ans.push_back(a[n - 1].second + 1);
  sum -= a[n - 1].first;
  int l = n - 1;
  for (int i = n - 2; i >= 0; --i) {
    if (sum < a[i + 1].first) {
      break;
    }
    sum -= a[i].first;
    --l;
  }

  for (int i = l; i < n - 1; ++i) ans.push_back(a[i].second + 1);
  sort(ans.begin(), ans.end());

  n = ans.size();

  cout << n << endl;
  for (int i = 0; i < n; ++i) cout << ans[i] << " ";
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