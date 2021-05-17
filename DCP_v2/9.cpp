/*
  author : Anand

	Problem 9
	This problem was asked by Airbnb.

	Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

	For example, [2, 4, 6, 8] should return 12, since we pick 4 and 8. [5, 1, 1, 5] should return 10, since we pick 5 and 5.
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

int getLargestNonAdjacentSum(vector<int> arr) {
	int n = arr.size();
	int pick = 0, notPick = 0;
	
	pick = arr[0];

	for(int i = 1 ; i < n ; ++i) {
		int newPick = notPick + arr[i];
		int newNotPick = max(pick, notPick);
		pick = newPick;
		notPick = newNotPick;
	}

	return max(pick, notPick);
}

void solve() {
  assert(getLargestNonAdjacentSum({2,4,6,8}) == 12);
  assert(getLargestNonAdjacentSum({5,1,1,5}) == 10);
  assert(getLargestNonAdjacentSum({5, 5, 10, 100, 10, 5}) == 110);
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