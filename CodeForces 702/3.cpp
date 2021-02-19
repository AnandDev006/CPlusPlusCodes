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
  int T;
  cin >> T;
  set<int> cubes;
  for (int i = 1; i * i * i < 1e12; ++i) {
    cubes.insert(i * i * i);
  }
  while (T--) {
    int n;
    cin >> n;
    bool flag = false;
    for (auto it = cubes.begin(); *it <= n / 2; ++it) {
      if (cubes.find(n - *it) != cubes.end()) {
        flag = true;
        break;
      }
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int tc = 1;
  // cin >> tc;
  for (int t = 1; t <= tc; ++t) solve(t);

  return 0;
}