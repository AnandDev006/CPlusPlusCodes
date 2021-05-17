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
  vector<int> n(4);
  cin >> n[0] >> n[1] >> n[2] >> n[3];

  vector<vector<pair<int, int> > > a(4);
  auto cmp = [](pair<int, int> x, pair<int, int> y) { return x.first < y.first; };

  for (int i = 0; i < 4; ++i) {
    a[i].resize(n[i]);
    for (int j = 0; j < n[i]; ++j) {
      cin >> a[i][j].first;
      a[i][j].second = j;
    }
    sort(a[i].begin(), a[i].end(), cmp);
  }

  vector<int> m(3);
  vector<set<pair<int, int> > > x(3);
  for (int i = 0; i < 3; ++i) {
    cin >> m[i];
    int u, v;
    for (int j = 0; j < m[i]; ++j) {
      cin >> u >> v;
      x[i].insert({u - 1, v - 1});
    }
  }

  vector<vector<pair<int, int> > > b(2);

  for (int i = 0; i < n[1]; ++i) {
    pair<int, int> minim = {INF, -1};
    for (int j = 0; j < n[0]; ++j) {
      if (x[0].find({a[0][j].second, a[1][i].second}) != x[0].end())
        continue;

      minim = {a[0][j].first + a[1][i].first, a[1][i].second};
      break;
    }
    if (minim.second != -1)
      b[0].push_back(minim);
  }

  for (int i = 0; i < n[2]; ++i) {
    pair<int, int> minim = {INF, -1};
    for (int j = 0; j < n[3]; ++j) {
      if (x[2].find({a[2][i].second, a[3][j].second}) != x[2].end())
        continue;

      minim = {a[2][i].first + a[3][j].first, a[2][i].second};
      break;
    }
    if (minim.second != -1)
      b[1].push_back(minim);
  }

  sort(b[0].begin(), b[0].end(), cmp);
  sort(b[1].begin(), b[1].end(), cmp);
  m[0] = b[0].size();
  m[1] = b[1].size();

  int ans = INF;
  for (int i = 0; i < m[0]; ++i) {
    for (int j = 0; j < m[1]; ++j) {
      if (x[1].find({b[0][i].second, b[1][j].second}) != x[1].end())
        continue;

      ans = min(ans, b[0][i].first + b[1][j].first);
      break;
    }
  }

  cout << (ans == INF ? -1 : ans) << endl;
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int tc = 1;
  // cin >> tc;
  for (int t = 1; t <= tc; ++t) solve(t);

  return 0;
}