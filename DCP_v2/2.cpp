/*
  author : Anand
  
    Problem 2
	This problem was asked by Uber.

	Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

	For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

	Follow-up: what if you can't use division?
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

vector<int> notSelfProductArray(vector<int> arr) {
	int n = arr.size();
	vector<int> left(n, 1);
	vector<int> right(n, 1);
	for(int i = 1 ; i < n ; ++i) {
		left[i] = arr[i-1] * left[i-1];
	}
	for(int i = n-2 ; i >= 0 ; --i) {
		right[i] = right[i+1] * arr[i+1];
	}
	vector<int> ans(n, 1);
	for(int i = 0 ; i < n ; ++i) {
		ans[i] = left[i] * right[i];
	}
	return ans;
}

template<typename T>
bool isVectorEqual(vector<T> v1, vector<T> v2) {
	return v1 == v2;
}

void solve() {
	assert( isVectorEqual(notSelfProductArray({1, 2, 3, 4, 5}) ,{120, 60, 40, 30, 24}) );
	assert( isVectorEqual(notSelfProductArray({3, 2, 1}) ,{2, 3, 6}) );
	assert( isVectorEqual(notSelfProductArray({3, 2, 1}) ,{2, 3, 5}) == false );
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