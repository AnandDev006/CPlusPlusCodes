/*
  author : Anand

    Problem 13
    This problem was asked by Amazon.

    Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

    For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".
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

int findLongestSubStringWithAtmostKDistChars(string s, int k) {
    int dist = 0;
    int len = 0;
    int n = s.size();
    int l = 0, r = 0;
    vector<int> cnt(26, 0);
    for(r = 0 ; r < n ; ++r) {
        if(++cnt[s[r] - 'a'] == 1) {
            ++dist;
        }
        while(dist > k) {
            if(--cnt[s[l++] - 'a'] == 0) {
                --dist;
            }
        }
        len = max(len, r - l + 1);
    }
    return len;
}

void solve() {
  assert(findLongestSubStringWithAtmostKDistChars("abcba", 2) == 3);
  assert(findLongestSubStringWithAtmostKDistChars("abaabc", 2) == 5);
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