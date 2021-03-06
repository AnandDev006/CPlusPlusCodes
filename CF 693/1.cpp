1 /*
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
  int w, h, n;
  cin >> w >> h >> n;
  if ((w & (~(w - 1))) * (h & (~(h - 1))) >= n) {
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