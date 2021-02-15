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
  string s, t;
  cin >> s >> t;
  if (s.size() > t.size()) swap(s, t);
  int lenS = s.size(), lenT = t.size();

  if (lenS == lenT) {
    if (s == t) {
      cout << s << endl;
    } else {
      cout << "-1\n";
    }
    return;
  }

  int lcm = (lenS * lenT) / __gcd(lenS, lenT);
  string ans = "";

  int p = 0;
  for (int i = 0; i < lcm; ++i) {
    ans += s[p++];
    p %= lenS;
  }
  p = 0;
  for (int i = 0; i < lcm; ++i) {
    if (ans[i] != t[p++]) {
      cout << "-1\n";
      return;
    }
    p %= lenT;
  }
  cout << ans << endl;
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; ++t) solve(t);

  return 0;
}