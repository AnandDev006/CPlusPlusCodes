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
  map<int, int> freq;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++freq[x];
  }
  
  vector<int> freqArr;
  set<int> freqSet;
  for (auto x : freq) {
    freqArr.push_back(x.second);
    freqSet.insert(x.second);
  }

  int ans = INF;
  for (int y : freqSet) {
    int tot = 0;
    for (int z : freqArr)
      if (z >= y)
        tot += (z - y);
      else
        tot += z;
    ans = min(ans, tot);
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