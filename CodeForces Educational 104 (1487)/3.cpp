/*
  author : Anand
*/

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define int long long
#define ll long long

/* <DEBUG> */

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}

#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

/* </DEBUG> */

const int INF = 1e18 + 5;
const int MOD = 1000000007;
const int N = 1e7;
const int K = 25;

void solve(int tc = 1) {
  int n;
  cin >> n;
  if (n & 1) {
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        cout << (((i + j) & 1) ? -1 : 1) << " ";
  } else {
    vector<vector<int> > dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i += 2) {
      dp[i][i + 1] = dp[i + 1][i] = 0;
      for (int j = i + 2; j < n; j += 2) {
        dp[i][j] = 1;
        dp[i][j + 1] = -1;
        dp[i + 1][j] = -1;
        dp[i + 1][j + 1] = 1;
      }
    }
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        cout << dp[i][j] << " ";
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