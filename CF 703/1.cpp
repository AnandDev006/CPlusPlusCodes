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
  int x, sum = 0, req = 0, flag = 1;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    sum += x;
    req += i;
    flag &= (sum >= req);
  }
  cout << (flag ? "YES\n" : "NO\n");
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; ++t) solve(t);

  return 0;
}