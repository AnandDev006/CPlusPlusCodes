/*
  author : Anand

 	Problem 7
	This problem was asked by Facebook.

	Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

	For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

	You can assume that the messages are decodable. For example, '001' is not allowed.
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

int decode(string s) {
	if(s[0] == '0') return 0;
	
	int n = s.size();
	vector<int> ways(n+1, 0);
	
	ways[0] = ways[1] = 1;
	for(int i = 2 ; i <= n ; ++i) {
		if(s[i-1] > '0') ways[i] += ways[i-1];
		if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7')) ways[i] += ways[i-2];
	}
	
	return ways[n];
}

void solve() {
  assert(decode("111") == 3);
  assert(decode("11") == 2);
  assert(decode("81") == 1);
  assert(decode("1111") == 5);
  assert(decode("1311") == 4);
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