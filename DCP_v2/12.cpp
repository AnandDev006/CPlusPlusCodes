/*
  author : Anand

    Problem 12
    This problem was asked by Amazon.

    There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. Given N, write a function that returns the number of unique ways you can climb the staircase. The order of the steps matters.

    For example, if N is 4, then there are 5 unique ways:

    1, 1, 1, 1
    2, 1, 1
    1, 2, 1
    1, 1, 2
    2, 2
    What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X? For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
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

int findNumUniqueWays(int n, vector<int> steps) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i = 0 ; i < n ; ++i) {
        for(int step : steps) {
            if(i + step <= n) {
                dp[i + step] += dp[i];
            }
        }
    }
    return dp[n];
}

void solve() {
  assert( findNumUniqueWays(4, {1, 2}) == 5);
  assert( findNumUniqueWays(4, {1, 3, 5}) == 3);
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