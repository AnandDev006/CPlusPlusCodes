/*
  author : Anand

  	Problem 4
	This problem was asked by Stripe.

	Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

	For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

	You can modify the input array in-place.
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

vector<int> a(N);
vector<int> dp(N);
int n;

int findFirstMissing(vector<int> arr) {
	n = arr.size();
	int neg = 0;
	for(int i = 0 ; i < n ; ++i) {
		if(arr[i] < 0) {
			arr[i] = 0;
			++neg;
		}
	}
	for(int i = 0 ; i < n ; ++i) {
		int idx = abs(arr[i]) - 1;
		if(idx >= 0 && idx < n) {
			arr[idx] = -abs(arr[idx]);
		}
	}
	for(int i = 0 ; i < n ; ++i) {
		if(arr[i] < 0) continue;
		return i+1;
	}
	return n + 1 - neg;
}

void solve() {
	assert( findFirstMissing({3, 4, -1, 1}) == 2 );
	assert( findFirstMissing({1, 2, 0}) == 3 );
	assert( findFirstMissing({1, 2, 3}) == 4 );
	assert( findFirstMissing({1, 2, 5}) == 3 );
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