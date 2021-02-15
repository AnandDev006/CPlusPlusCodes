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
  vector<int> a(n) ;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.rbegin(), a.rend());

  int isAlice = 1, scoreAlice = 0, scoreBob = 0;

  for (int i = 0; i < n; ++i) {
    if (isAlice && a[i] % 2 == 0) scoreAlice += a[i];
    if (!isAlice && a[i] % 2 != 0) scoreBob += a[i];
    isAlice = !isAlice;
  }

  if (scoreAlice > scoreBob) {
    cout << "Alice\n";
  } else if (scoreAlice == scoreBob) {
    cout << "Tie\n";
  } else {
    cout << "Bob\n";
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