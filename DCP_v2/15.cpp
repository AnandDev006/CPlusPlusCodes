/*
  author : Anand

    Problem 15
    This problem was asked by Facebook.

    Given a stream of elements too large to store in memory, pick a random element from the stream with uniform probability.
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

void randomPicker(int x) {
    static int cnt = 0;
    static int result;
    ++cnt;
    if(cnt == 1) {
        result = x;
    } else {
        int idx = rand() % cnt;
        if(idx == cnt - 1) {
            result = x;
        }
    }
    cout << result << endl;
}

void solve() {
    srand(time(NULL));
    vector<int> stream({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    for(int num : stream) {
        randomPicker(num);
    }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}