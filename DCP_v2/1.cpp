/*
  author : Anand
    
    Problem 1
	Given a list of numbers, return whether any two sums to k. For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

	Bonus: Can you do this in one pass?
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

bool twoSum(vector<int> input, int k) {
	unordered_set<int> bucket;
	n = input.size();
	for(int i = 0 ; i < n ; ++i) {
		if(bucket.find(input[i]) != bucket.end()) {
			return true;
		}
		bucket.insert(k - input[i]);
	}
	return false;
}

void solve() {
	assert(twoSum({10, 15, 3, 7}, 17) == true);
	assert(twoSum({10, 15, 3, 7}, 10) == true);
	assert(twoSum({10, 15, 3, 1}, 10) == false);
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