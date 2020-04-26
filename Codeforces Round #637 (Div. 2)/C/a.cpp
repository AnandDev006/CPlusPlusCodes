#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define int long long
#define ll long long

#ifdef ONLINE_JUDGE
#define DEBUG1(format) {}
#define DEBUG(format, ...) {} //Intentionally blank
#else
#define DEBUG1(format) fprintf(stderr, format )
#define DEBUG(format, ...) fprintf(stderr, format, __VA_ARGS__)
#endif

const int INF = 1e18 + 5;
const int MOD = 1000000007;
const double ZERO = 10e-9;
const int N = 3e5, M = N;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;

  /* ALGO TO SEE IF INPUTS ARE GROUPS OF NUMS SUCH THAT
  a[i] + 1 == a[i] in same group and for X < Y all e
  lements of group Y are less than smallest of group X */
  vector<int> pos(n);
  for (int i = 0 ; i < n ; ++i)
    pos[a[i] - 1] = i;

  vector<bool> seen(n);
  for (int i = 0 ; i < n ; i++) {
    if (seen[i]) continue;
    int val = pos[i];
    while ( val < n) {
      seen[val] = true;
      if ( val + 1 == n) break;
      if ( seen[val + 1]) break;
      if ( a[val] + 1 == a[val + 1]) {
        ++val;
        continue;
      }
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

signed main() {
  cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}