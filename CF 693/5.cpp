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

void solve(int tc = 1) {
  int n;
  cin >> n;
  vector<pair<int, pair<int, int>>> a(n);
  for (int i = 0; i < n; ++i) {
    a[i].first = i;
    cin >> a[i].second.first;
    cin >> a[i].second.second;
    if (a[i].second.first > a[i].second.second) swap(a[i].second.first, a[i].second.second);
  }

  auto cmp = [&](pair<int, pair<int, int>> x, pair<int, pair<int, int>> y) { return x.second.first < y.second.first; };
  sort(a.begin(), a.end(), cmp);

  vector<int> res(n, -1);
  vector<int> minimSecondVal(n, INF);
  vector<int> minimSecondIdx(n, -1);
  int minVal = INF,  minValPos = -1;
  int pt = -1;

  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      if (a[i].second.first != a[i - 1].second.first) {
        pt = i - 1;
      }
      if (pt >= 0) {
        if (a[i].second.second > minimSecondVal[pt]) {
          res[a[i].first] = minimSecondIdx[pt];
        }
      }
    }
    if (a[i].second.second < minVal) {
      minVal = a[i].second.second;
      minValPos = a[i].first + 1;
    }
    minimSecondVal[i] = minVal;
    minimSecondIdx[i] = minValPos ;
  }
  for (int i = 0; i < n; ++i) cout << res[i] << " ";
  cout << endl;
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int tc = 1;
  cin >> tc;
  for (int t = 0; t < tc; t++) solve(t + 1);

  return 0;
}