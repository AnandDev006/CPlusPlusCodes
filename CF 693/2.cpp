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

void solve() {
  int n;
  cin >> n;
  int count_1 = 0;
  int sum = 0;
  int x;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    sum += x;
    count_1 += (x == 1);
  }
  if (sum % 2 == 0 && (sum % 4 == 0 || count_1 / 2 != 0)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}